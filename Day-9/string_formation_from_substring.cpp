// User function template for C++
class Solution {
  public:
    int isRepeat(string s) {
        // Function to check if a string can be constructed by repeating a substring
        int n = s.size();
        
        // Step 1: Create LPS (Longest Prefix Suffix) array for KMP pattern preprocessing
        vector<int> lps(n, 0);
        lps[0] = 0; // First character has no proper prefix-suffix match
        
        int len = 0; // length of the current longest prefix-suffix
        int j = 1;   // current index in string
        
        // Step 2: Build LPS array
        while (j < n) {
            if (s[len] == s[j]) {
                // If characters match, increase current prefix-suffix length
                len++;
                lps[j] = len;
                j++;
            }
            else {
                if (len == 0) {
                    // If no prefix-suffix match, set to 0 and move ahead
                    lps[j] = 0;
                    j++;
                } 
                else {
                    // If mismatch after some matches, use previously computed LPS
                    len = lps[len - 1];
                }
            }
        }
        
        // Step 3: Get the length of the longest proper prefix which is also a suffix
        int last = lps[n - 1];
        
        // Step 4: If the remaining part (n - last) divides n evenly,
        // it means the string is made up of repeating substring(s)
        if (last != 0 && n % (n - last) == 0)
            return 1;  // String is a repeated pattern
        
        // Step 5: Otherwise, it's not a repeating pattern
        return 0;
    }
};
