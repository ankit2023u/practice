// Problem: Convert a given positive integer N into its corresponding Excel column title.
// Example: 1 -> A, 26 -> Z, 27 -> AA, 28 -> AB, etc.

class Solution {
  public:
    string ExcelColumn(int N) {
        // Initialize an empty string to store the resulting column name
        string ans = "";

        // Step 1: Convert number to Excel column code (base-26 with A-Z mapping)
        while (N > 0) {
            N--;  // Adjust for 1-based indexing (Excel columns start at 1 = 'A')
            
            // Get the current character by taking modulo 26
            char ch = char('A' + (N % 26));
            
            // Append this character to the result (will be in reverse order)
            ans += ch;
            
            // Move to the next "digit" in Excel column numbering
            N /= 26;
        }
        
        // Step 2: Reverse the constructed string to get the correct order
        reverse(ans.begin(), ans.end());
        
        // Step 3: Return the final Excel column title
        return ans;
    }
};
