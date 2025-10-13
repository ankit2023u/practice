class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return;  // Single element → no next permutation possible

        int i = n - 1;
        int swap_pos = n - 2;
        bool found = false;

        // Step 1: Find the first index (from the end) where nums[i-1] < nums[i]
        // This marks the pivot point where the sequence stops being non-increasing.
        // Example: [1, 3, 5, 4, 2] → pivot is 3 (since 3 < 5)
        while (i > 0) {
            if (nums[i - 1] >= nums[i]) {
                i--;  // Move left until we find the breaking point
            } else {
                swap_pos = i - 1;
                found = true;
                break;
            }
        }

        // Step 2: If a pivot was found, we need to find the next larger element to swap with
        if (found) {
            int mini_pos = swap_pos;

            // Find the smallest element greater than nums[swap_pos] to the right
            for (int j = n - 1; j > swap_pos; j--) {
                if (nums[j] > nums[swap_pos] && mini_pos == swap_pos) {
                    mini_pos = j;
                } else {
                    if (nums[j] > nums[swap_pos] && nums[j] < nums[mini_pos])
                        mini_pos = j;
                }
            }

            // Step 3: Swap pivot element with the next greater element
            swap(nums[mini_pos], nums[swap_pos]);

            // Step 4: Reverse the suffix (right part) to make it the smallest possible
            // because after the swap, we want the next *immediate* permutation
            reverse(nums.begin() + i, nums.end());
            return;
        }

        // Step 5: If no pivot was found → array is in descending order
        // So the next permutation is the smallest (ascending order)
        reverse(nums.begin(), nums.end());
    }
};
