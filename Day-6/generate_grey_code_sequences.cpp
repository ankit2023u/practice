/* Returns an array of all n-bit Gray code sequences.
   The function generates the Gray codes recursively. */
class Solution {
  public:
    vector<string> generateCode(int N) {
        // Base case: For 1-bit Gray code, simply return "0" and "1"
        if(N == 1) 
            return {"0", "1"};
        
        // Step 1: Recursively generate (N-1)-bit Gray codes
        vector<string> prev = generateCode(N - 1);
        int k = prev.size();                  // Number of codes in (N-1)-bit sequence
        
        // Step 2: Prepare a vector to hold the current N-bit Gray codes (double the size)
        vector<string> curr(2 * k);
        
        // Step 3: Prefix '0' to the first half (same order as previous)
        for(int i = 0; i < k; i++){
            curr[i] = "0" + prev[i];
        }
        
        // Step 4: Prefix '1' to the second half (reverse order of previous)
        for(int i = k; i < 2 * k; i++){
            curr[i] = "1" + prev[2 * k - i - 1];
        }
        
        // Step 5: Return the complete N-bit Gray code sequence
        return curr;
    }
};
