                            
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Function to extract individual digits
// of a number and store them in a vector
vector<int> extractDigits(int N) {
    // Initialize an empty
    // vector to store the digits
    vector<int> ans;  
    
    // Loop to extract digits
    // until N becomes 0
    while(N > 0){
        // Extract the last digit of N
        int remainder = N % 10;
        // Store the last digit
        // in the vector
        ans.push_back(remainder);
         // Remove the last digit from N
        N /= 10;
    }
    
    // Reverse the vector to get
    // digits in the correct order
    reverse(ans.begin(), ans.end());  
    
    // Return the vector
    // containing individual digits
    return ans; 
}


int main() {
    int N = 329823;
    cout << "N: "<< N << endl;
    vector<int> digits = extractDigits(N);
    cout << "Extracted Digits: ";
    for(auto num: digits){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
                            
                        