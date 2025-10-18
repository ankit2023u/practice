// Problem: Given a string containing both uppercase and lowercase letters,
// sort all lowercase letters among themselves and uppercase letters among themselves,
// while keeping their original positions (case-wise) fixed.
class Solution {
  public:
    string caseSort(string& s) {
        // Get the length of the input string
        int n = s.size();
        
        // Separate strings for uppercase and lowercase characters
        string u = "";  // stores uppercase characters
        string l = "";  // stores lowercase characters
        
        // Step 1: Split the string into uppercase and lowercase groups
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                l += s[i];  // collect lowercase letters
            } else {
                u += s[i];  // collect uppercase letters
            }
        }
        
        // Step 2: Sort both groups individually
        sort(u.begin(), u.end());
        sort(l.begin(), l.end());
        
        // Step 3: Reconstruct the final string
        // preserving original case positions
        string ss = s;  // copy original structure
        int j = 0;      // pointer for lowercase letters
        int k = 0;      // pointer for uppercase letters
        
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ss[i] = l[j];  // replace with next sorted lowercase
                j++;
            } else {
                ss[i] = u[k];  // replace with next sorted uppercase
                k++;
            }
        }
        
        // Step 4: Return the reconstructed case-sorted string
        return ss;
    }
};
