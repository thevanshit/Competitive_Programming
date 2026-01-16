#include <iostream>
#include <vector>
using namespace std;

vector <int> twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    vector <int> result;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            result.push_back(left);
            result.push_back(right);
            break;
        }
        else if (sum < target) left++;
        else right--;
    }
    return result;
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    return 0;
}
