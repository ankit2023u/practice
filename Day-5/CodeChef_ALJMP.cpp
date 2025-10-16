#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O setup (optional)

	int t, n;
	cin >> t;  // Read number of test cases
	
	while(t--){
	    cin >> n;  // Read integer n for each test case
	    
	    // Output (n + 1) / 2
	    // This effectively gives the ceiling value of n/2
	    // Example: 
	    // n = 5 → (5 + 1)/2 = 3
	    // n = 6 → (6 + 1)/2 = 3
	    // So it rounds up when n is odd.
	    
	    cout << (n + 1) / 2 << endl;
	}
}
