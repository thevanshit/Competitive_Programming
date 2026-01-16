#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeFactors(int n) {
    vector<int> factors;

    if (n % 2 == 0) {
        factors.push_back(2);
        while (n % 2 == 0) n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0) n /= i;
        }
    }

    if (n > 2)
        factors.push_back(n);

    return factors;
}

int main() {
    int num = 2340;
    vector<int> primeFactors = getPrimeFactors(num);

    for (int p : primeFactors)
        cout << p << " ";
    cout << endl;

    return 0;
}
