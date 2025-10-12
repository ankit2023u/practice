// Comments by ChatGPT
// This function replaces every element in the array with the next greatest element to its right.
// It traverses the array from right to left, keeping track of the maximum element seen so far.
// The rightmost element is replaced with -1, as there is no element to its right.

class Solution {
  public:
    /* Function to replace every element with the
    next greatest element */
    vector<int> nextGreatest(vector<int> arr) {
        // Get the size of the array
        int n = arr.size();
        int maxi = -1; // Initialize maximum to -1 for the rightmost element
        
        vector<int> ng(n);

        // Traverse the array from right to left
        for(int i = n-1; i >= 0; i--){
            ng[i] = maxi;             // Replace current element with current maximum
            maxi = max(maxi, arr[i]); // Update maximum if current element is larger
        }

        // Return the modified array
        return ng;
    }
};
