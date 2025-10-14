// User function Template for C++
class Solution {
  public:
    // Function to reverse a given string in place
    string reverseString(string& s) {
        // Get length of the string
        int n = s.size();

        // Swap characters from both ends moving toward the center
        for (int i = 0; i < (n + 1) / 2; i++) {
            swap(s[i], s[n - i - 1]);
        }

        // Return the reversed string
        return s;
    }
};
