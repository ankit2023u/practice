#include <bits/stdc++.h>
using namespace std;

// Custom function 'gcnd' to compute a modified "GCD-like" value
// based on given conditions for two integers s and l
int gcnd(int s, int l) {
    // Ensure s <= l
    if (s > l) swap(s, l);

    // Case 1: If both numbers are equal, return one less than them
    if (s == l) return s - 1;

    // Case 2: If they differ by 1, return the larger number minus 2
    if (s == l - 1) return l - 2;
    
    // Case 3: Otherwise, return the larger number minus 1
    return l - 1;
}

int main() {
    // Fast input-output setup
	// your code goes here
	int t, n;
	cin >> t;  // Number of test cases
	
	while(t--){
	    cin >> n;  // Size of array for this test case
	    
	    vector<int> nums(n);
	    
	    // Input array elements
	    for(int i = 0; i < n; i++){
	        cin >> nums[i];
	    }
	    
	    // Sort the array to easily access the largest and second largest elements
	    sort(nums.begin(), nums.end());

        // Store the largest and second largest numbers
        int maxi = nums[n-1];
        int sec_maxi = nums[n-2];
	    
	    // Compute the initial gcnd value using the two largest numbers
	    int gcnd_val = gcnd(maxi, sec_maxi);
	    
	    // Compare 'maxi' with all smaller elements (except itself)
	    // and keep track of the maximum gcnd value found
	    for(int i = 0; i < n-1; i++){
	        gcnd_val = max(gcnd(maxi, nums[i]), gcnd_val);
	    }
	    
	    // Compare 'sec_maxi' with all smaller elements (except itself and maxi)
	    // to see if a better gcnd value can be found
	    for(int i = 0; i < n-2; i++){
	        gcnd_val = max(gcnd(sec_maxi, nums[i]), gcnd_val);
	    }
	    
	    // Print the final maximum gcnd value for this test case
	    cout << gcnd_val << endl;
	}
}
