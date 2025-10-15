//Approach 1
class Solution {
public:
    char getMaxOccuringChar(string& s) {
        // Get the size of the input string
        int n = s.size();

        // Create a frequency array to store the count of each lowercase character
        // freq[0] -> 'a', freq[1] -> 'b', ..., freq[25] -> 'z'
        vector<int> freq(26, 0);

        // Traverse the string and count the occurrences of each character
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++; // Increment the count of the corresponding character
        }

        // Initialize a variable to store the index of the character with maximum frequency
        int ch = 0;

        // Traverse the frequency array to find the index with the maximum frequency
        for(int i = 1; i < 26; i++){
            if(freq[i] > freq[ch]){
                ch = i; // Update the index if a higher frequency is found
            }
        }

        // Convert the index back to the corresponding character and return it
        return char(ch + 'a'); 
    }
};


//Approach 2
class Solution {
public:
    char getMaxOccuringChar(string& s) {
        // Get the size of the input string
        int n = s.size();

        // Frequency array to count occurrences of each lowercase letter
        // freq[0] corresponds to 'a', freq[1] to 'b', ..., freq[25] to 'z'
        vector<int> freq(26, 0);

        // Initialize the character with maximum frequency to the first character in the string
        char ch = s[0];

        // Traverse the string
        for(int i = 0; i < n; i++){
            // Increment the frequency of the current character
            freq[s[i] - 'a']++;

            // If current character has higher frequency than current max, update max character
            if(freq[s[i] - 'a'] > freq[ch - 'a']){
                ch = s[i];
            }
            // If current character has same frequency but is lexicographically smaller, update max character
            else if(freq[s[i] - 'a'] == freq[ch - 'a'] && s[i] < ch){
                ch = s[i];
            }
        }

        // Return the character with maximum frequency (smallest lexicographically in case of tie)
        return ch; 
    }
};
