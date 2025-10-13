class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int maj = nums[0];  // Candidate for majority element
        int count = 1;      // Count of current candidate

        // Step 1: Traverse the array to find the potential majority candidate
        for (int i = 1; i < n; i++) {
            if (!count) {
                // If count becomes 0, pick the current element as new candidate
                maj = nums[i];
                count++;
            }
            else if (nums[i] == maj) {
                // If current element matches the candidate, increase count
                count++;
            }
            else {
                // Otherwise, cancel out one occurrence of current candidate
                count--;
            }
        }

        // Step 2: Return the candidate
        // For this problem, it’s guaranteed that a majority element exists,
        // so we don’t need a second pass for validation.
        return maj;
    }
};
