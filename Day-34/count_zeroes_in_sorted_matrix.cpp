// Back-end complete function Template for C++

class Solution {
public:
    int countZeros(vector<vector<int>> A) {
        // A is an n x n matrix where each row is sorted (0s followed by 1s).
        int n = A.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            // Start by assuming the whole row has zeros.
            // row_count tracks how many entries to the right could be zero
            // until we find the transition point.
            int row_count = n;

            // Scan row from right to left because 1s appear on the right end.
            for(int j = n - 1; j >= 0; j--){
                if(A[i][j]){
                    // Found a 1 → shrink potential zero segment.
                    row_count--;
                }
                else{
                    // Hit the first zero from the right.
                    // All remaining row_count positions are zeros.
                    count += row_count;
                    break; // No need to scan further; zeros end here.
                }
            }
        }

        return count;
    }
};
