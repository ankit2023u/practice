#include <iostream>
#include <bits/stdc++.h>   // Includes all standard C++ headers
using namespace std;

int main() {
    int t, n;
    
    cin >> t;  // Read number of test cases
    
    while (t--) {
        cin >> n;  // Read number of elements in the current test case
        
        int temp;
        int maxi = INT_MIN;  // Initialize maximum value as smallest possible integer
        
        // Read all elements and find the maximum
        for (int i = 0; i < n; i++) {
            cin >> temp;                  // Read current element
            maxi = max(temp, maxi);       // Update maximum if current element is larger
        }
        
        // Output the maximum value for this test case
        cout << maxi << endl;
    }
    
    return 0;  // Program executed successfully
}
