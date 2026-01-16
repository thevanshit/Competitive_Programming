#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::vector<int> primesInRange(std::vector<std::vector<int>>& queries) {
        if (queries.empty()) {
            return {};
        }

        int maxVal = 0;
        for (const auto& query : queries) {
            maxVal = std::max(maxVal, query[1]);
        } 

        std::vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;  
        for (int p = 2; p * p <= maxVal; ++p) {
            if (isPrime[p]) {
                for (int i = p * p; i <= maxVal; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        std::vector<int> primeCount(maxVal + 1, 0);
        for (int i = 1; i <= maxVal; ++i) {
            primeCount[i] = primeCount[i - 1];
            if (isPrime[i]) {
                primeCount[i]++;
            }
        }

        std::vector<int> result;
        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];
            if (start == 0) {
                result.push_back(primeCount[end]);
            } else {
                result.push_back(primeCount[end] - primeCount[start - 1]);
            }
        }

        return result;
    }
};

int main() {
    std :: vector<vector<int>> queries = { {2, 5}, {4, 7} };
    Solution solution;

    auto result = solution.primesInRange(queries);

    cout << "The number of primes in the given ranges are: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
