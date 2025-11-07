class Solution {
  public:
    bool searchInSorted(vector<int>& arr, int k) {
        // Function to check if element 'k' exists in sorted array 'arr'
        // Uses iterative binary search approach
        
        int high = arr.size() - 1;  // rightmost index
        int low = 0;                // leftmost index
        
        // Continue searching while there’s a valid range
        while (low <= high) {
            // Compute middle index (avoids overflow)
            int mid = low + (high - low) / 2;
            
            // If middle element equals target, found it
            if (arr[mid] == k) {
                return true;
            }
            // If middle element is smaller than target,
            // discard left half and move right
            else if (arr[mid] < k) {
                low = mid + 1;
            }
            // If middle element is greater than target,
            // discard right half and move left
            else {
                high = mid - 1;
            }
        }
        
        // If loop ends, element was not found
        return false;
    }
};
