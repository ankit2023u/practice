// User function template for C++
class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        // Function to count the number of zeroes in a sorted binary array (containing only 0s and 1s)
        // Assumption: The array is sorted in non-increasing order (e.g., [1,1,1,0,0])
        
        int n = arr.size();  // size of the array
        int count = 0;       // count of leading 1's
        
        // Traverse array to find the first 0
        for (int i = 0; i < n; i++) {
            // Once we hit the first 0, stop counting
            if (arr[i] == 0) break;
            count++;  // count all 1's before the first 0
        }
        
        // Total zeroes = total elements - number of 1's before first zero
        return n - count;
    }
};
