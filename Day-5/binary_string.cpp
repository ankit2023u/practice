class Solution {
public:
    int binarySubstring(string& s) {
        // Get the size of the input string
        int n = s.size();
        
        // o_count stores the number of consecutive '1's seen so far
        int o_count = 0;

        // count stores the total number of binary substrings (substrings with consecutive '1's)
        int count = 0;

        // Traverse the string
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                // If this is not the first '1' in the sequence,
                // each previous '1' can pair with the current '1' to form a new substring
                if(o_count) count += o_count;

                // Increment the consecutive '1's counter
                o_count++;
            }
        }

        // Return the total number of binary substrings
        return count;
    }
};
