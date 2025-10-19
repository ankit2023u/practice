// User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // Step 1: Create a frequency array for all lowercase alphabets
        vector<int> freq(26, 0);
        
        int n = S.size();
        for (int i = 0; i < n; i++) {
            freq[S[i] - 'a']++;
        }
        
        // Step 2: Initialize two pointers for traversal from both ends
        int l = 0;
        int r = n - 1;
        
        // 'rev' indicates the current direction of removal:
        // false → left to right, true → right to left
        bool rev = false;
        
        // Step 3: Traverse the string and mark characters to remove
        while (l <= r) {
            if (rev) {
                // Current direction: right to left
                if (freq[S[r] - 'a'] > 1) {
                    // If frequency > 1, mark it as removed and flip direction
                    freq[S[r] - 'a']--;
                    S[r] = '0'; // mark as deleted
                    rev = !rev; // switch direction
                }
                r--; // move right pointer leftwards
            } else {
                // Current direction: left to right
                if (freq[S[l] - 'a'] > 1) {
                    // If frequency > 1, mark it as removed and flip direction
                    freq[S[l] - 'a']--;
                    S[l] = '0'; // mark as deleted
                    rev = !rev; // switch direction
                }
                l++; // move left pointer rightwards
            }
        }
        
        // Step 4: Rebuild the answer string without removed characters
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (S[i] >= 'a' && S[i] <= 'z') ans += S[i];
        }
        
        // Step 5: If the final direction is reversed, reverse the string
        if (rev) reverse(ans.begin(), ans.end());
        
        // Step 6: Return the final processed string
        return ans;
    }
};
