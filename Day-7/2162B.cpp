#include <iostream>
#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

int main() {
    int t, n;
    cin >> t;  // Read the number of test cases
    
    while (t--) {
        cin >> n;  // Read the size of the string
        
        string s;
        cin >> s;  // Read the binary string (containing '0's and '1's)
        
        int count = 0;  // To count the number of '0's in the string
        
        // Count the number of '0' characters in the string
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') count++;
        }
        
        // Print the total count of '0's
        cout << count << endl;
        
        // Print the 1-based indices of all '0' characters
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') cout << i + 1 << " ";
        }
        cout << endl;  // Move to the next line after printing all indices
    }
}
