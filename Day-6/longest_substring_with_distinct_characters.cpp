class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // Function to find the length of the longest substring 
        // without repeating characters in a given string
        
        int n = s.size();                  // Length of the input string
        vector<int> counts(26, 0);         // Frequency array for lowercase letters ('a' to 'z')
        
        int i = 0;                         // Left pointer of the sliding window
        int j = 0;                         // Right pointer of the sliding window
        int max_len = 1;                   // Variable to store maximum length of unique substring
        
        // Use sliding window approach
        while(j < n){
            counts[s[j] - 'a']++;          // Include current character in the window
            
            // If duplicate character found, shrink window from left
            while(counts[s[j] - 'a'] > 1){
                counts[s[i] - 'a']--;      // Remove leftmost character from window
                i++;                       // Move left pointer forward
            }
            
            // Update maximum length of unique substring
            max_len = max(max_len, j - i + 1);
            j++;                           // Expand window to the right
        }
        
        // Return the length of the longest substring with all unique characters
        return max_len;
    }
};
