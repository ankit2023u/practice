// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 2;  // compare mid with mid+1, so stop at n-2
        int ans = n - 1;   // default: last element (handles fully increasing array)

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If current element is greater than next, peak lies on the left side (including mid)
            if (arr[mid] > arr[mid + 1]) {
                ans = mid;      // mid is a potential maximum
                high = mid - 1; // shrink towards left
            } else {
                // Still rising, so peak lies to the right
                low = mid + 1;
            }
        }
        return arr[ans]; // return peak value
    }
};
