class Solution {
  public:
    int lastIndex(string s) {
        // Function to find the last index of character '1' in a binary string 's'
        // Returns -1 if '1' is not found
        
        int n = s.size();   // length of the string
        int last = -1;      // stores the last index of '1', default -1 (not found)
        
        // Traverse the string from end to start
        for (int i = n - 1; i >= 0; i--) {
            // If current character is '1', record index and stop search
            if (s[i] == '1') {
                last = i;
                break;
            }
        }
        
        // Return the last found index (or -1 if none)
        return last;
    }
};
