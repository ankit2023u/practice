// Comments by ChatGPT
// This function finds a peak element in the array 'arr' using binary search.
// A peak element is an element that is greater than its neighbors.
// The function returns the index of any one peak element.

class Solution {
public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();
        if (n == 1) return 0; // If only one element, it is the peak

        int low = 0, high = n - 1;

        // Binary search for peak element
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < arr[mid + 1])
                low = mid + 1;  // Peak must be in the right half
            else
                high = mid;     // Peak is in the left half or at mid
        }

        // 'low' will point to a peak element
        return low;
    }
};
