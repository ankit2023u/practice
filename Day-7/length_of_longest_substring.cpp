class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        // Function to find the length of the longest substring
        // containing all unique characters (no repetitions)

        int n = s.size();  // Length of the input string
        
        // Frequency array to track character occurrences
        // Assuming only lowercase letters 'a' to 'z'
        vector<int> freq(26, 0);
        
        // Two pointers for the sliding window
        int i = 0;  // Left boundary
        int j = 0;  // Right boundary
        
        int len = 0;  // Stores the length of the longest unique substring found so far
        
        // Expand the window using j
        while (j < n) {
            // Include the current character into the window
            freq[s[j] - 'a']++;
            
            // If a character repeats, shrink the window from the left
            while (freq[s[j] - 'a'] > 1) {
                freq[s[i] - 'a']--;  // Remove character at left boundary
                i++;                  // Move left boundary forward
            }
            
            // Update the maximum length found so far
            len = max(len, j - i + 1);
            
            // Move right boundary forward
            j++;
        }
        
        // Return the length of the longest substring with all unique characters
        return len;
    }
};
