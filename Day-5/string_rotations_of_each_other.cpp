class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // Function to check if s2 is a rotation of s1 using KMP pattern matching
        
        int n = s1.size();
        vector<int> lps(n, 0); // LPS (Longest Prefix Suffix) array for KMP
        
        // Step 1: Preprocess s1 to build its LPS array
        lps[0] = 0; // The first character has no proper prefix-suffix match
        int len = 0; // Current length of matching prefix-suffix
        int j = 1;   // Current index in s1
        
        while (j < n) {
            if (s1[len] == s1[j]) {
                // Characters match → extend prefix-suffix
                len++;
                lps[j] = len;
                j++;
            }
            else {
                if (len == 0) {
                    // No prefix-suffix match → set 0 and move forward
                    lps[j] = 0;
                    j++;
                }
                else {
                    // Mismatch after some matches → use previous LPS value
                    len = lps[len - 1];
                }
            }
        }
        
        // Step 2: Concatenate s2 with itself
        // A rotation of s1 must appear as a substring in s2 + s2
        string s = s2 + s2;
        
        // Step 3: Use KMP to search for s1 in s2 + s2
        j = 0; // index for s1 (pattern)
        for (int i = 0; i < 2 * n; i++) {
            // If mismatch, move j using LPS array
            while (j > 0 && s1[j] != s[i]) 
                j = lps[j - 1];
            
            // If characters match, move forward in both
            if (s1[j] == s[i]) 
                j++;
            
            // If we matched entire s1, s2 is a rotation of s1
            if (j == n) 
                return true;
        }
        
        // Step 4: If not found, they are not rotations
        return false;
    }
};
