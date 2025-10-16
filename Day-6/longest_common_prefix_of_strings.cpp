// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // Function to find the longest common prefix among all strings in the array
        
        int min_len = INT_MAX;      // Variable to store the length of the shortest string
        int n = arr.size();         // Total number of strings
        
        // Step 1: Find the minimum string length (since prefix can't be longer than the shortest string)
        for(int i = 0; i < n; i++){
            min_len = min(min_len, (int)arr[i].size());
        }
        
        string lcp = "";            // To store the longest common prefix
        
        // Step 2: Compare characters column-wise for all strings up to min_len
        for(int j = 0; j < min_len; j++){
            char ch = arr[0][j];    // Character from the first string to compare
            
            // Step 3: Check if all strings have the same character at this position
            for(int i = 1; i < n; i++){
                if(arr[i][j] != ch) 
                    return lcp;     // Mismatch found, return prefix so far
            }
            
            // If all strings matched at this position, append the character to result
            lcp += ch;
        }
        
        // Step 4: Return the final longest common prefix
        return lcp;
    }
};
