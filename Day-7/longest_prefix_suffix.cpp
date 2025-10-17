class Solution {
  public:
    int getLPSLength(string &s) {
        // Function to compute the length of the Longest Proper Prefix 
        // which is also a Suffix (LPS) for the entire string.
        // This is essentially the last value in the KMP LPS array.

        int n = s.size();  // Length of the input string
        int i = 0;         // Length of the previous longest prefix-suffix
        int j = 1;         // Current index being processed in the string
        
        // Initialize LPS array with zeros
        vector<int> lps(n, 0);
        
        // Build the LPS array
        while (j < n) {
            // Case 1: Characters match — extend current prefix-suffix length
            if (s[i] == s[j]) {
                i++;           // Increase the prefix-suffix length
                lps[j] = i;    // Store it for position j
                j++;           // Move to next character
            }
            // Case 2: Mismatch after at least one match
            else if (s[i] != s[j] && i > 0) {
                // Fall back to the previous longest prefix-suffix length
                i = lps[i - 1];
            }
            // Case 3: Mismatch when no prefix-suffix match yet
            else {
                lps[j] = 0;    // No common prefix-suffix
                j++;           // Move to next character
            }
        }
        
        // The last value in the LPS array represents 
        // the length of the longest prefix that is also a suffix
        return lps[n - 1];
    }
};
