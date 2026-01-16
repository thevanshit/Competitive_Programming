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
    int missing, repeating;

    long long cal_sum = (long long)n * (n + 1) / 2;
    long long cal_sq_sum = (long long)n * (n + 1) * (2 * n + 1) / 6;

    long long arr_sum = 0;
    long long arr_sq_sum = 0;

    for (int i = 0; i < n; i++) {
        arr_sum += (long long)arr[i];
        arr_sq_sum += (long long)arr[i] * arr[i];
    }

    long long diff = cal_sum - arr_sum; // M - R
    long long diff_sq = cal_sq_sum - arr_sq_sum; // M^2 - R^2

    long long add = diff_sq / diff; // M + R

    // Final calculation with correct assignment
    missing = (int)((diff + add) / 2); // M
    repeating = (int)(missing - diff); // R

    return {missing, repeating}; // {missing, repeating}
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
