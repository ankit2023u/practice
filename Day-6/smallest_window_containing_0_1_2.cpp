// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Function to find the length of the smallest substring 
        // that contains at least one '0', one '1', and one '2'
        
        int n = S.size();                  // Length of the input string
        vector<int> freq(3, 0);            // Frequency array for '0', '1', and '2'
        int i = 0;                         // Left pointer of the sliding window
        int j = 0;                         // Right pointer of the sliding window
        int min_len = -1;                  // Variable to store the minimum valid window length
        
        // Sliding window traversal
        while(j < n){
            freq[S[j] - '0']++;            // Include current character in window
            
            // Try to shrink window from the left while it still contains all three digits
            while(freq[0] && freq[1] && freq[2] && (freq[S[i] - '0'] - 1)){
                freq[S[i] - '0']--;        // Remove character at left
                i++;                       // Move left pointer rightward
            }
            
            // If current window contains all '0', '1', and '2'
            if(freq[0] && freq[1] && freq[2]){
                // Update the minimum length found so far
                if(min_len == -1){
                    min_len = j - i + 1;
                } 
                else {
                    min_len = min(min_len, j - i + 1);
                }
            }
            
            j++; // Expand window to the right
        }
        
        // Return the length of the smallest valid substring (or -1 if none found)
        return min_len;
    }
};
