/*
 * This class encapsulates the solution.
 */
class Solution {
public:
    /**
     * @brief Creates the Longest Proper Prefix which is also Suffix (LPS) array.
     * * This is the standard preprocessing function for the KMP pattern searching algorithm.
     * lps[i] stores the length of the longest proper prefix of str[0...i] 
     * which is also a suffix of str[0...i].
     * * @param str The input string (e.g., "s$rev")
     * @param n The length of the string
     * @return A vector<int> containing the computed LPS array.
     */
    vector<int> create_lps(string &str, int n) {
        // Initialize an LPS array of size n
        vector<int> lps(n);
        
        // lps[0] is always 0 because a single character has no proper prefix.
        lps[0] = 0;
        
        // 'j' is the main iterator for the string, starting from the second character.
        int j = 1;
        
        // 'i' tracks the length of the current matching prefix.
        int i = 0;
        
        // Iterate through the string from the second character
        while (j < n) {
            // Case 1: The characters match
            if (str[i] == str[j]) {
                // The match length increases.
                i++;
                // Store the new length (i) at lps[j].
                lps[j] = i;
                // Move to the next character in the string.
                j++;
            }
            // Case 2: The characters do NOT match
            else {
                // Subcase 2a: 'i' is not 0.
                // We have a prefix match that just failed.
                if (i != 0) {
                    // We "fall back" by setting 'i' to the LPS value of the
                    // *previous* character in the prefix. This is the core
                    // KMP insight: we don't need to re-scan from 0.
                    i = lps[i - 1];
                }
                // Subcase 2b: 'i' is already 0.
                // We have no prefix match at all.
                else {
                    // This character (j) starts no new prefix/suffix match.
                    lps[j] = 0;
                    // Move to the next character.
                    j++;
                }
            }
        }
        
        // Return the fully computed LPS array
        return lps;
    }

    /**
     * @brief Calculates the minimum characters to add to the FRONT of a string
     * to make it a palindrome.
     *
     * The logic is to find the length of the *longest prefix* of the
     * original string 's' that is *already* a palindrome.
     *
     * Example: s = "AACECAAA"
     * The longest palindromic prefix is "AACECAA" (length 7).
     * The part that is *not* part of this prefix is "A" (the last char).
     * We must add the reverse of this non-matching part ("A") to the front.
     * So, we add "A" -> "AAACECAAA".
     *
     * The number of chars to add is n - length(longest_palindromic_prefix).
     * In the example: 8 - 7 = 1.
     *
     * @param s The original string.
     * @return The minimum number of characters to add.
     */
    int minChar(string &s) {
        // Create a reversed copy of the original string
        string rev = s;
        int n = rev.size();
        reverse(rev.begin(), rev.end());
        
        // THE TRICK:
        // Combine the original string, a unique delimiter, and the reversed string.
        // s = "race", rev = "ecar" -> "race$ecar"
        // s = "AACECAAA", rev = "AAACECAA" -> "AACECAAA$AAACECAA"
        s = s + "$" + rev;
        
        // Create the LPS array for this new, combined string.
        // The length is 2*n (for s + rev) + 1 (for '$').
        vector<int> lps = create_lps(s, 2 * n + 1);
        
        // The *last* value of the LPS array (lps[2*n]) gives us the
        // length of the longest prefix of the *original* string 's'
        // that is also a suffix of the *reversed* string 'rev'.
        //
        // This is *exactly* the length of the longest palindromic prefix of 's'.
        //
        // Example: "race$ecar"
        // lps[8] will be 1 (for "r").
        // Longest palindromic prefix of "race" is "r". Length 1.
        //
        // Example: "AACECAAA$AAACECAA"
        // lps[16] will be 7 (for "AACECAA").
        // Longest palindromic prefix of "AACECAAA" is "AACECAA". Length 7.
        
        // The number of characters to add is the total length (n)
        // minus the length of the part that is already a palindrome prefix (lps[2*n]).
        return n - lps[2 * n];
    }
};
