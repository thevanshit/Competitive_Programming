#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector <int> &vec){

    for (auto Itr : vec)
    {
        cout << Itr << " ";
    }
    cout << endl;

}

int MaxProfitFromStock(vector <int> &vec){

    int mini = vec[0];
    int profit = 0;
    
    int cost = 0;
    for (int i = 1; i < vec.size(); i++)
    {
        cost = vec[i] - mini;
        profit = max(profit,cost);
        mini = min(vec[i],mini);
    }
    
    return profit;
}

int main(){

    vector <int> vec;
    vec = {7, 1, 5, 3, 6, 4};

    cout << "The given price of the stock is : " << endl;
    PrintTheArray(vec);

    int MaxProfit;
    MaxProfit = MaxProfitFromStock(vec);

    cout << "The Maximum Profit we get from the Selling the Stocks is : " << MaxProfit << endl;
}