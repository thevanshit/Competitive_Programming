#include <iostream>
#include <vector>
using namespace std;

// Function to print a vector
void PrintVec(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to find the missing and repeating number
pair<int, int> findMissingAndRepeating(const vector<int>& arr) {
    int n = arr.size();

    // Calculate sum and sum of squares for numbers 1..n
    long long sum_n = n * (n + 1) / 2;
    long long sum_n2 = n * (n + 1) * (2 * n + 1) / 6;

    // Calculate sum and sum of squares for array elements
    long long arr_sum = 0, arr_sum2 = 0;
    for (int num : arr) {
        arr_sum += num;
        arr_sum2 += 1LL * num * num; // Use 1LL for long long multiplication
    }

    // Calculate differences
    long long S1 = sum_n - arr_sum;          // M - R
    long long S2 = sum_n2 - arr_sum2;        // M^2 - R^2

    // M + R = S2 / S1
    long long M_plus_R = S2 / S1;

    // Calculate missing and repeating numbers
    int missing = (int)((S1 + M_plus_R) / 2);
    int repeating = (int)(missing - S1);

    return {missing, repeating};
}

int main() {
    vector<int> arr = {4, 3, 6, 2, 1, 1}; // n=6, missing=5, repeating=1
    cout << "Given vector Array is : ";
    PrintVec(arr);

    auto res = findMissingAndRepeating(arr);
    cout << "Missing: " << res.first << "\n";
    cout << "Repeating: " << res.second << "\n";
    return 0;
}
