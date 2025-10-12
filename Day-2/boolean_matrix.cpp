// Comments by ChatGPT
// This function modifies the given matrix such that if any cell is 1, 
// its entire row and column are set to 1.
// It first records the rows and columns containing 1s, then updates the matrix.
class Solution {
public:
    void booleanMatrix(vector<vector<int>>& mat) {
        int m = mat.size();       // Number of rows
        int n = mat[0].size();    // Number of columns
        set<int> rows;            // To store row indices that contain 1
        set<int> cols;            // To store column indices that contain 1

        // Step 1: Record which rows and columns contain 1s
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        // Step 2: Update the matrix based on recorded rows and columns
        for(int i = 0; i < m; i++){
            if(rows.find(i) != rows.end()){
                // Entire row becomes 1 if this row had any 1
                for(int j = 0; j < n; j++) mat[i][j] = 1;
            }
            else{
                // Otherwise, set 1 for columns that were marked
                for(int j = 0; j < n; j++){
                    if(cols.find(j) != cols.end()) mat[i][j] = 1;
                }
            }
        }
    }
};
