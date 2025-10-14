// User function template for C++
class Solution {
  public:
    // Returns the area of the largest rectangle consisting of 1's
    // when we are allowed to swap columns in each row
    int maxArea(vector<bool> mat[], int r, int c) {
        // Step 1: Build histogram of heights of consecutive 1s for each column
        vector<vector<int>> hist(r, vector<int>(c, 0));

        // Initialize first row
        for (int j = 0; j < c; j++) 
            if (mat[0][j]) hist[0][j] = 1;

        // Build up histogram for remaining rows
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] && hist[i - 1][j]) {
                    // If current cell is 1, and cell above is also 1
                    // increase height by 1
                    hist[i][j] = hist[i - 1][j] + 1;
                } 
                else if (mat[i][j]) {
                    // If current cell is 1 but above is 0, start new height = 1
                    hist[i][j] = 1;
                }
                // If current cell is 0, height remains 0 by initialization
            }
        }

        // Step 2: For each row in histogram, maximize area by reordering columns
        // Since swapping columns is allowed, we can sort each row descending
        int max_area = 0;
        for (auto row : hist) {
            sort(row.begin(), row.end()); // sort ascending for easier indexing
            int i = 0;
            int j = c - 1;

            // Step 3: Two-pointer approach to calculate area
            while (i <= j) {
                int w = j - i + 1;               // current width
                int h = min(row[i], row[j]);     // limiting height
                max_area = max(max_area, w * h); // update maximum area

                // Move pointer which limits the height
                if (row[i] < row[j]) i++;
                else j--;
            }
        }

        // Step 4: Return the maximum rectangle area found
        return max_area;
    }
};
