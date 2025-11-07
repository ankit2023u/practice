// User function template for C++

class Solution {
  public:
    vector<int> firstAndLast(int x, vector<int> &arr) {
        // Get the size of the array
        int n = arr.size();
        int low = 0, high = n - 1;

        // ---------- FIND FIRST OCCURRENCE ----------
        int first = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {
                first = mid;     // Possible first occurrence found
                high = mid - 1;  // Move left to find earlier occurrence
            }
            else if (arr[mid] > x) {
                high = mid - 1;  // Search left half
            }
            else {
                low = mid + 1;   // Search right half
            }
        }

        // If element not found, return {-1}
        if (first == -1) return {-1};

        // ---------- FIND LAST OCCURRENCE ----------
        low = 0;
        high = n - 1;
        int last = first;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {
                last = mid;      // Possible last occurrence found
                low = mid + 1;   // Move right to find later occurrence
            }
            else if (arr[mid] > x) {
                high = mid - 1;  // Search left half
            }
            else {
                low = mid + 1;   // Search right half
            }
        }

        // Return both first and last positions of x
        return {first, last};
    }
};
