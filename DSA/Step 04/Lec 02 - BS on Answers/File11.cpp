#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if we can make m bouquets by day 'day'
bool canMakeBouquets(const vector<int>& bloomDay, int day, int m, int k) {
    int count = 0;
    int bouquetCount = 0;
    for (int bloom : bloomDay) {
        if (bloom <= day) {
            count++;
        } else {
            bouquetCount += count / k;
            count = 0;
        }
    }
    // Add bouquets from the last batch
    bouquetCount += count / k;

    return bouquetCount >= m;
}


int minDays(vector<int>& bloomDay, int m, int k) {
    if (m * k > bloomDay.size()){
        return -1;
    }
    int min = *min_element(bloomDay.begin(), bloomDay.end());
    int max = *max_element(bloomDay.begin(), bloomDay.end());

    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (canMakeBouquets(bloomDay,i,m,k)){
            return i;
        }
    }
    
    return -1;
}

int main() {
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    int result = minDays(bloomDay, m, k);
    if (result != -1)
        cout << "Minimum days to make " << m << " bouquets: " << result << endl;
    else
        cout << "Impossible to make " << m << " bouquets." << endl;
    return 0;
}
