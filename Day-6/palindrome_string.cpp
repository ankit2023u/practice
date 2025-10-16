class Solution {
  public:
    bool isPalindrome(string& s) {
        // Function to check if a given string is a palindrome

        int n = s.size();          // Length of the string
        int mid = (n + 1) / 2;     // Midpoint of the string (used to stop comparison halfway)
        
        // Compare characters from the beginning and the end moving toward the center
        for(int i = 0; i < mid; i++){
            // If any corresponding characters differ, it's not a palindrome
            if(s[i] != s[n - i - 1]) 
                return false;
        }
        
        // If all characters match symmetrically, it's a palindrome
        return true;
    }
};
