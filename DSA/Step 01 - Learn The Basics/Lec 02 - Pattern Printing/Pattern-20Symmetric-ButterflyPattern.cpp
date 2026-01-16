#include <bits/stdc++.h>
using namespace std;

void pattern20(int N)
{
    for (int i = 1; i <= N; i++) {

        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }

        for (int j = 1; j <= 2 * (N - i); j++) {
            cout << "  ";
        }

        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }

        cout << endl;
    }

    for (int i = N - 1; i >= 1; i--) {

        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }

        for (int j = 1; j <= 2 * (N - i); j++) {
            cout << "  ";
        }

        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }

        cout << endl;
    }
}

int main()
{
    int N = 5;
    pattern20(N);
    return 0;
}
