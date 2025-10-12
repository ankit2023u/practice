// Comments by ChatGPT
// This function finds the transition point in a binary array 'arr' consisting of 0s followed by 1s.
// The transition point is the index of the first occurrence of 1.
// It uses binary search for efficient O(log n) lookup.
// Returns the index of the first 1, or -1 if no 1 is present.

class Solution {
  public:
    int transitionPoint(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();
        int low = 0;
        int high = n-1;
        
        // Binary search for the first occurrence of 1
        while(low < high){
            int mid = low + (high-low)/2;
            
            if(arr[mid]){
                high = mid;  // Possible transition point, search left
            }
            else{
                low = mid+1; // Search right
            }
        }

        // Check if the found index contains 1
        if(arr[high] == 1) return high;
        return -1; // No 1 found
    }
};
