class Solution {
  public:
    int minFlips(string& s) {
        // Function to find the minimum number of bit flips required 
        // to make the binary string alternate (e.g., "0101..." or "1010...")
        
        int n = s.size();          // Length of the input binary string
        
        int zero_beg = 0;          // Flips required if string starts with '0'
        int one_beg = 0;           // Flips required if string starts with '1'
        
        // Traverse each character and compare with the expected pattern
        for(int i = 0; i < n; i++){
            if(i % 2){  // Odd index positions
                // For pattern starting with '0': expected '1' → flip if '0'
                if(s[i] == '0'){
                    zero_beg++;
                }
                // For pattern starting with '1': expected '0' → flip if '1'
                else{
                    one_beg++;
                }
            }
            else{  // Even index positions
                // For pattern starting with '1': expected '1' → flip if '0'
                if(s[i] == '0'){
                    one_beg++;
                }
                // For pattern starting with '0': expected '0' → flip if '1'
                else{
                    zero_beg++;
                }
            }
        }
        
        // Return the minimum flips required between both possible alternating patterns
        return min(zero_beg, one_beg);
    }
};
