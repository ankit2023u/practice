class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size() - 1;
        
        int ans = -1; // stores index of best candidate <= x
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int curr = arr[mid];

            if (curr <= x) {
                ans = mid;       // valid floor, try to find a closer one on the right
                low = mid + 1;
            } else {
                high = mid - 1;  // too large, move left
            }
        }
        return ans; // -1 if no element <= x exists
    }
};
