class Solution {
  public:
    string reverseWords(string &s) {
        // Function to reverse the order of words in a string
        // Words are separated by '.'

        int n = s.size();   // Length of the input string
        string w = "";      // Temporary string to hold individual words (in reverse order)
        string ans = "";    // Final answer string with words reversed
        bool word_start = false; // Flag to track when a word starts

        // Traverse the string from the end to the beginning
        for(int i = n - 1; i >= 0;){
            // If currently in a word and we find a '.', it means the word has ended
            if(word_start && s[i] == '.'){
                reverse(w.begin(), w.end()); // Reverse the word to restore correct order
                ans += w;                    // Append the word to the result
                ans += ".";                  // Add a '.' separator
                w = "";                      // Clear the temporary word
                word_start = false;          // Reset flag for the next word
            }
            // If character is not '.', add it to current word
            else if(s[i] != '.'){
                word_start = true;
                w += s[i];
                i--;
            }
            // Skip extra '.' characters if any
            else{
                i--;
            }
        }

        // Handle the last word (first word in the original string)
        if(s[0] != '.'){
            reverse(w.begin(), w.end());
            ans += w;
        }
        else{
            // If the string started with '.', remove the trailing '.'
            ans.pop_back();
        }

        // Return the reversed word sequence
        return ans;
    }
};
