#include <iostream>
using namespace std;

int squareRoot(int x) {
    if (x == 0 || x == 1) return x;

    int ans = -1;
    for (int i = 1; i <= x; i++)
    {
        if (i * i <= x){
            ans = i;
        }
        else {
            break;
        }
    }
    
    return ans; // floor(sqrt(x))
}

int main() {
    int x;
    x = 95;

    int result = squareRoot(x);
    cout << "🔹 Integer square root of " << x << " is: " << result << endl;

    return 0;
}
