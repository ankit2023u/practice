class Solution {
  public:
    int getMinimumDays(int N, string S, vector<int> &P) {
        // Function to find minimum days required to make no two adjacent characters equal
        // by removing characters in order specified by array P
        
        int countf = 0; // Count of adjacent equal pairs
        vector<bool> equal(N-1, true); // Tracks which adjacent pairs are still equal
        
        // Step 1: Count initial adjacent equal pairs
        for (int i = 0; i < N - 1; i++) {
            if (S[i] == S[i + 1]) {
                countf++;        // Increment count of equal pairs
                equal[i] = false; // Mark this pair as not "resolved"
            }
        }
        
        // Step 2: If there are no equal pairs initially, no days are needed
        if (!countf) return 0;
        
        // Step 3: Remove characters in the order given by P
        for (int j = 0; j < N; j++) {
            S[P[j]] = '?'; // Mark the character as removed
            
            // Step 3a: Check the left neighbor pair
            if (P[j] > 0) {
                if (!equal[P[j] - 1]) countf--; // If it was an unresolved equal pair, reduce count
                equal[P[j] - 1] = true;         // Mark this pair as resolved
            }
            
            // Step 3b: Check the right neighbor pair
            if (P[j] < N - 1) {
                if (!equal[P[j]]) countf--; // If it was an unresolved equal pair, reduce count
                equal[P[j]] = true;         // Mark this pair as resolved
            }
            
            // Step 3c: If all adjacent equal pairs are resolved, return current day count
            if (countf == 0) return j + 1; // Days are 1-based
        }
        
        // Step 4: If not all pairs resolved after N removals, return N+1 (should not happen normally)
        return N + 1;
    }
};
