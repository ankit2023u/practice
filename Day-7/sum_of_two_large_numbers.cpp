// User function template for C++
class Solution {
  public:
    string findSum(string &s1, string &s2) {
        // Function to find the sum of two large numbers represented as strings
        
        int m = s1.size();
        int n = s2.size();
        
        // Ensure s1 is not longer than s2 for simpler processing
        if (m > n) return findSum(s2, s1);
        
        // Pointers to the end of both strings (least significant digits)
        int i = m - 1;
        int j = n - 1;
        
        string ans = "";  // Resultant sum (will be reversed at the end)
        int c = 0;        // Carry
        
        // Traverse both strings from right to left
        while (j >= 0) {
            // Get current digits (or 0 if shorter string is exhausted)
            int a = (i >= 0) ? (s1[i] - '0') : 0;
            int b = s2[j] - '0';
            
            // Calculate sum of current digits + carry
            int s = a + b + c;
            
            // Update carry
            if (s > 9) c = 1;
            else c = 0;
            
            // Append current digit to answer
            ans += char('0' + (s % 10));
            
            // Move to next digits
            if (i >= 0) i--;
            j--;
        }
        
        // If carry remains after final addition, append it
        if (c) ans += "1";
        
        // Remove any trailing zeros (they appear because ans is built in reverse)
        for (int k = ans.size() - 1; k >= 0 && ans[k] == '0'; k--) {
            ans.pop_back();
        }
        
        // If result becomes empty (both inputs were zero)
        if (ans.size() == 0) ans = "0";
        
        // Reverse to get the final sum in correct order
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
