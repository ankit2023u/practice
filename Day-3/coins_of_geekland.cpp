class Solution {
  public:
    int Maximum_Sum(vector<vector<int>> &mat, int N, int K) {
        // Function to find the maximum sum of any K x K submatrix in an N x N matrix

        // Step 1: Create a prefix sum matrix (1-based indexing)
        // dp[i][j] stores the sum of elements from (0,0) to (i-1,j-1)
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

        int sum = 0;

        // Step 2: Compute prefix sum for the first row
        for (int i = 1; i <= N; i++) {
            sum += mat[0][i - 1];
            dp[1][i] = sum;
        }

        // Step 3: Compute prefix sum for the first column
        sum = 0;
        for (int i = 1; i <= N; i++) {
            sum += mat[i - 1][0];
            dp[i][1] = sum;
        }

        int answer = INT_MIN; // Will store the maximum K x K submatrix sum

        // Step 4: Fill the rest of the prefix sum matrix
        for (int i = 2; i <= N; i++) {
            for (int j = 2; j <= N; j++) {
                // Standard 2D prefix sum relation:
                // dp[i][j] = mat[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]
                dp[i][j] = mat[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

                // Step 5: Once we have at least a K x K area, compute that submatrix's sum
                if (i >= K && j >= K) {
                    // Submatrix sum formula using inclusion-exclusion:
                    // Sum of submatrix with bottom-right corner (i, j):
                    // dp[i][j] - dp[i-K][j] - dp[i][j-K] + dp[i-K][j-K]
                    answer = max(answer, dp[i][j] - dp[i - K][j] - dp[i][j - K] + dp[i - K][j - K]);
                }
            }
        }

        // Step 6: Return the maximum K x K submatrix sum found
        return answer;
    }
};
