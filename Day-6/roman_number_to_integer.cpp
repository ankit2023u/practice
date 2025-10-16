class Solution {
  public:
    int romanToDecimal(string &s) {
        // Function to convert a Roman numeral string to its decimal (integer) value
        
        // Map to store the integer values of Roman numeral characters
        map<char, int> val = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int n = s.size();             // Length of the input Roman numeral string
        int ans = val[s[n-1]];        // Initialize answer with value of last character
        
        // Traverse the string from second-last character to the beginning
        for(int i = n - 2; i >= 0; i--){
            // If the current character is greater than or equal to the next character, add its value
            if(val[s[i]] >= val[s[i+1]]){
                ans += val[s[i]];
            }
            // Otherwise, subtract its value (handles cases like IV = 4, IX = 9)
            else{
                ans -= val[s[i]];
            }
        }
        
        // Return the final decimal value
        return ans;
    }
};
