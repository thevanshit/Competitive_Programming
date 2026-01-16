#include <iostream>
#include <iomanip>
using namespace std;

// Function to multiply number 'mid' by itself 'n' times
double multiply(double mid, int n) {
    double result = 1;
    for (int i = 1; i <= n; i++){
        result *= mid;
    }
    return result;
}

// Function to find the nth root of x using binary search
double nthRoot(double x, int n, double precision = 1e-6) {
    
    for (int i = 0; i < x; i++)
    {
        if (multiply(i,n) == x){
            return i;
        }
        else if (multiply(i,n) > x){
            break;
        }
    }
    
    return -1;  // or high (both close enough)
}

int main() {
    double x;
    int n;
    cout << "Enter number (x): ";
    cin >> x;
    cout << "Enter root (n): ";
    cin >> n;

    double result = nthRoot(x, n);

    cout << fixed << setprecision(6);
    cout << "\n🔹 The " << n << "th root of " << x << " is approximately: " << result << endl;

    return 0;
}
