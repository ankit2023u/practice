class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();  // Get the size of the square matrix

        // Step 1: Transpose the matrix
        // Transposing converts rows into columns:
        // swap(matrix[i][j], matrix[j][i]) for all i < j
        // Example before transpose:
        // [1 2 3]
        // [4 5 6]
        // [7 8 9]
        // After transpose:
        // [1 4 7]
        // [2 5 8]
        // [3 6 9]
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        // Reversing rows gives a 90° clockwise rotation
        // Example after reversing each row:
        // [7 4 1]
        // [8 5 2]
        // [9 6 3]
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
