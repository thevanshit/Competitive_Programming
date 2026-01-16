#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<int> &vec) {
    for (auto Itr : vec) {
        cout << Itr << " ";
    }
    cout << endl;
}

pair<int, int> MaxProfitFromStock(vector<int> &vec) {
    int n = vec.size();
    int mini = vec[0];
    int min_index = 0;
    int profit = 0;
    int buy_day = 0, sell_day = 0;

    for (int i = 1; i < n; i++) {
        int cost = vec[i] - mini;
        if (cost > profit) {
            profit = cost;
            buy_day = min_index;
            sell_day = i;
        }
        if (vec[i] < mini) {
            mini = vec[i];
            min_index = i;
        }
    }

    return {buy_day, sell_day};
}

int main() {
    vector<int> vec = {7, 1, 5, 3, 6, 4};

    cout << "The given price of the stock is:\n";
    PrintTheArray(vec);

    pair<int, int> MaxProfit = MaxProfitFromStock(vec);

    cout << "\nTo maximize profit:" << endl;
    cout << "Buy on Day " << MaxProfit.first << " (Price = " << vec[MaxProfit.first] << ")" << endl;
    cout << "Sell on Day " << MaxProfit.second << " (Price = " << vec[MaxProfit.second] << ")" << endl;
    cout << "Maximum Profit = " << vec[MaxProfit.second] - vec[MaxProfit.first] << endl;

    return 0;
}