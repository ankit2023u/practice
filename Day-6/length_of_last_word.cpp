class Solution {
public:
    int lengthOfLastWord(string s) {
        // Function to find the length of the last word in a given string
        
        int n = s.size();          // Length of the input string
        bool start_word = false;   // Flag to indicate if we’ve started counting the last word
        int len = 0;               // Variable to store the length of the last word
        
        // Traverse the string from the end to the beginning
        for(int i = n - 1; i >= 0; i--){
            // Skip trailing spaces until the first non-space character is found
            if(!start_word && s[i] == ' ') continue;

            // If a space is found *after* starting a word, that means the last word has ended
            if(s[i] == ' '){
                break;
            }
            else {
                // Count characters of the last word
                start_word = true;
                len++;
            }
        }

        // Return the length of the last word found
        return len;
    }
};
