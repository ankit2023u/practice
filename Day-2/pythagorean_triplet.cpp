// Comments by ChatGPT
// This function checks if there exists a Pythagorean triplet in the array.
// It uses a boolean array to store the squares of the numbers for O(1) look-up.
class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();
        // Boolean array to check if a square exists
        vector<bool> exists(1001*1001, false);
        // Boolean array to check if a number is present
        vector<bool> present(1001, false);
        
        // Populate the arrays with squares and presence
        for(int i = 0; i < n; i++){
            long long sq = 1ll*arr[i]*arr[i];  // Square of current element
            present[arr[i]] = true;            // Mark number as present
            exists[sq] = true;                 // Mark its square as existing
        }
        
        // Check all pairs (i, j) to see if their squares sum to another square
        for(int i = 0; i < 1001; i++){
            if(!present[i]) continue;          // Skip numbers not in array
            for(int j = i; j < 1001; j++){
                if(!present[j]) continue;      // Skip numbers not in array
                long long val = 1ll*i*i + 1ll*j*j;  // Sum of squares
                if(val < exists.size() && exists[val]){
                    return true;              // Found a Pythagorean triplet
                }
            }
        }
        return false;  // No triplet found
    }
};
