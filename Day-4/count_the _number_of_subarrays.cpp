// User function Template for C++
class Solution {
  public:
    // Helper function to count subarrays with sum at most M
    long long count_atmost(int N, vector<int> &A, long long M) {
        long long sum = 0;    // Current sum of the sliding window
        long long count = 0;  // Count of subarrays with sum <= M
        int i = 0;            // Left pointer of the sliding window

        // Expand the window with right pointer j
        for (int j = 0; j < N; j++) {
            sum += 1ll * A[j];  // Include current element in the sum

            // Shrink window from left while sum exceeds M
            while (sum > M) {
                sum -= A[i];
                i++;
            }

            // All subarrays ending at j and starting from i..j are valid
            count += j - i + 1;
        }

        return count; // Total number of subarrays with sum <= M
    }

    // Main function to count subarrays with sum in range [L, R]
    long long countSubarray(int N, vector<int> A, long long L, long long R) {
        // Count subarrays with sum <= R
        long long atmostR = count_atmost(N, A, R);

        // Count subarrays with sum <= L-1
        long long atmostL_minus_one = count_atmost(N, A, L - 1);

        // Number of subarrays with sum in [L, R] = atmostR - atmost(L-1)
        return atmostR - atmostL_minus_one;
    }
};
