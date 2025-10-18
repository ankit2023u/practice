// Problem: Given two strings A and B of equal length, determine the minimum number of moves
// required to transform A into B using the following rule:
// You can only move characters from A's left part to the front (like rearranging from end).
// If transformation is impossible (different letters), return -1.

class Solution {
  public:
    int transform(string A, string B) {
        // Get the lengths of both strings
        int n = A.size();
        int m = B.size();
        
        // If lengths differ, transformation is not possible
        if (n != m) return -1;
        
        // Frequency trackers for uppercase and lowercase characters separately
        vector<int> u(26, 0);  // for 'A'–'Z'
        vector<int> l(26, 0);  // for 'a'–'z'
        
        // Step 1: Validate that A and B contain exactly the same set of characters
        // Increment counts for A, decrement for B
        for (int i = 0; i < n; i++) {
            if (A[i] >= 'A' && A[i] <= 'Z') {
                u[A[i] - 'A']++;  // count uppercase letter in A
            } else {
                l[A[i] - 'a']++;  // count lowercase letter in A
            }
            
            if (B[i] >= 'A' && B[i] <= 'Z') {
                u[B[i] - 'A']--;  // remove one occurrence for same uppercase letter in B
            } else {
                l[B[i] - 'a']--;  // remove one occurrence for lowercase letter in B
            }
        }
        
        // Step 2: If any count remains non-zero, A and B have mismatched characters
        for (int i = 0; i < 26; i++) {
            if (u[i] || l[i]) return -1;
        }
        
        // Step 3: Count how many characters from the end already match
        // Traverse from right to left comparing A and B
        int j = n - 1;  // pointer for string B
        for (int i = n - 1; i >= 0; i--) {
            if (A[i] == B[j]) {
                j--;  // move left in B when characters match
            }
        }
        
        // Step 4: The remaining unmatched characters count = number of moves needed
        return j + 1;
    }
};
