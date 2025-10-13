//https://codeforces.com/problemset/problem/2160/A
#include <iostream>
#include <bits/stdc++.h>  // Includes all standard C++ libraries
using namespace std;

int main() {
    int t, n;
    cin >> t;  // Number of test cases

    while (t--) {
        cin >> n;  // Size of the array

        vector<int> nums(n);
        bool found_zero = false;  // Flag to check if 0 exists in the array

        // Input the array and check if it contains zero
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (nums[i] == 0) found_zero = true;
        }

        int mex = 0;  // Default value of MEX (minimum excluded number)

        // If the array contains 0, then try to find the smallest missing positive integer
        if (found_zero) {
            sort(nums.begin(), nums.end());  // Sort the array to make scanning easier

            bool found = false;  // Will be set true if MEX is found within the array range
            int start = 0;       // Start from 0 to track consecutive numbers

            // Scan through the sorted numbers
            for (int i = 0; i < n; i++) {
                if (nums[i] == start) continue;  // Skip duplicates of current start

                if (nums[i] == start + 1) {
                    // If next integer is consecutive, move to next value
                    start++;
                } else {
                    // Found a gap — that means MEX = start + 1
                    mex = start + 1;
                    found = true;
                    break;
                }
            }

            // If loop ends with no gaps, then MEX = last element + 1
            if (!found) mex = nums[n - 1] + 1;
        }

        // If there was no zero in the array, MEX remains 0
        cout << mex << endl;
    }
}
