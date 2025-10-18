// Problem: Find the length of the smallest substring that contains all distinct characters of the input string.
class Solution {
  public:
    int findSubString(string& str) {
        // Get length of the input string
        int n = str.size();
        
        // Frequency array for each lowercase character
        vector<int> freq(26, 0);
        
        // 'win' stores distinct characters in the current window
        // 'all' stores all distinct characters present in the entire string
        set<int> win, all;
        
        // Step 1: Identify all unique characters in the string
        for (int i = 0; i < n; i++) {
            all.insert(str[i] - 'a');
        }
        
        // Two-pointer sliding window: i = left, j = right
        int i = 0;
        int j = 0;
        
        // Initialize answer with maximum possible value
        int min_len = INT_MAX;
        
        // Step 2: Expand window using 'j'
        while (j < n) {
            // Include current character in the frequency table
            freq[str[j] - 'a']++;
            
            // Add current character to the window set
            win.insert(str[j] - 'a');
            
            // Step 3: Try shrinking the window from the left (i)
            // as long as the window still contains all distinct characters
            // and the leftmost character occurs more than once
            while (win.size() == all.size() && freq[str[i] - 'a'] > 1) {
                freq[str[i] - 'a']--;
                i++;
            }
            
            // Step 4: If the window contains all distinct characters,
            // update the minimum window length
            if (win.size() == all.size())
                min_len = min(min_len, j - i + 1);
            
            // Move right pointer forward
            j++;
        }
        
        // Step 5: Final check after loop ends — in case smallest window ends at the last index
        while (win.size() == all.size() && freq[str[i] - 'a'] > 1) {
            freq[str[i] - 'a']--;
            i++;
        }
        
        if (win.size() == all.size())
            min_len = min(min_len, j - i + 1);
        
        // Step 6: Return the smallest window length containing all unique characters
        return min_len;
    }
};
