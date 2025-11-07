// User function template for C++
class Solution {
  public:
    bool match(string wild, string pattern) {
        // 'wild' = string with wildcards ('*' and '?')
        // 'pattern' = normal string
        // Return true if 'wild' matches 'pattern' completely
        
        int m = wild.size();
        int n = pattern.size();
        
        // dp[i][j] = true if first i characters of 'wild'
        // match first j characters of 'pattern'
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        // Base case: empty wildcard matches empty pattern
        dp[0][0] = true;
        
        // Handle patterns like "*", "**", "***", etc.
        // An empty pattern can only be matched by a wildcard
        // consisting entirely of '*' characters
        for (int i = 1; i <= m && wild[i-1] == '*'; i++) {
            dp[i][0] = true;
        }
        
        // Fill DP table
        for (int i = 1; i <= m; i++) {
            char w = wild[i-1];   // current character in wildcard
            
            for (int j = 1; j <= n; j++) {
                char ch = pattern[j-1];  // current character in pattern
                
                if (w == '*') {
                    // '*' can match:
                    //   1. zero characters → dp[i-1][j]
                    //   2. one or more characters → dp[i][j-1]
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else if (w == '?') {
                    // '?' matches exactly one character
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    // exact character match
                    dp[i][j] = dp[i-1][j-1] && (w == ch);
                }
            }
        }
        
        // Final answer: does entire wildcard match entire pattern
        return dp[m][n];
    }
};
