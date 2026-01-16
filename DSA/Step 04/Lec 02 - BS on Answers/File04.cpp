#include <iostream>
#include <iomanip>
using namespace std;

// Function to multiply number 'mid' by itself 'n' times
double multiply(double mid, int n) {
    double result = 1;
    for (int i = 0; i < n; ++i) {
        result *= mid;
    }
    return result;
}

// Function to find the nth root of x using binary search
double nthRoot(double x, int n, double precision = 1e-6) {
    
    double left = 0;
    double right = max(1.0,x);
    while (left <= right){
        double mid = left + (right - left) / 2;
        if (multiply(mid,n) == x){
            return mid;
        }
        else if (multiply(mid,n) < x){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    return left;
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
