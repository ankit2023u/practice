class Solution {
public:
    // Helper function to check if a given array forms an arithmetic progression (AP)
    bool check_ap(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return true;  // Single element is trivially an AP

        int d = nums[1] - nums[0];  // Common difference of first two elements

        // Check if all consecutive differences are equal to d
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] != d)
                return false;
        }
        return true;
    }

    // Main function to check if subarrays of nums (defined by l[i], r[i]) form an AP
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();  // Size of the main array
        int q = l.size();     // Number of queries

        vector<bool> ans(q, false);  // Result array for each query

        // Step 1: Process each query
        for (int i = 0; i < q; i++) {
            // Extract the subarray defined by [l[i], r[i]]
            vector<int> range_lr(nums.begin() + l[i], nums.begin() + r[i] + 1);

            // Step 2: Sort the subarray
            // Sorting is necessary because AP can exist in any order
            sort(range_lr.begin(), range_lr.end());

            // Step 3: Check if the sorted subarray forms an arithmetic progression
            ans[i] = check_ap(range_lr);
        }

        // Step 4: Return the result vector
        return ans;
    }
};
