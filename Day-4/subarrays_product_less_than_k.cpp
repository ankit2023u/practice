class Solution {
public:
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        // If k <= 1, no subarray product can be less than k (since all elements are positive)
        if (k <= 1) return 0; 
        
        long long prod = 1;   // Current product of elements in the sliding window
        long long count = 0;  // To store total count of valid subarrays

        int i = 0;  // Left pointer of the sliding window
        for (int j = 0; j < n; j++) {  // Expand window with right pointer j
            prod *= arr[j];  // Include current element in product

            // Shrink window from left while product becomes >= k
            while (i < n && prod >= k) {
                prod /= arr[i];
                i++;
            }

            // For each valid j, number of valid subarrays ending at j = (j - i + 1)
            // because all subarrays starting from i..j, i+1..j, ..., j..j are valid
            count += (j - i + 1);
        }

        // Return total number of subarrays with product < k
        return count;
    }
};
