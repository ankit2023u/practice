// Comments by ChatGPT
// This function searches for a target value in a 2D matrix where each row is sorted in ascending order.
// First, it identifies the possible row that may contain the target using binary search.
// Then, it performs binary search within that row to locate the target.
// Returns true if the target is found, false otherwise.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        // Check for empty matrix
        if (n == 0) return false;

        int m = matrix[0].size();
        // Check for rows that are empty
        if (m == 0) return false;

        // Binary search to find the row that could contain the target
        int low = 0;
        int high = n-1;
        bool is_row_found = false;
        int target_row;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(target < matrix[mid][0]){
                high = mid-1;
            }
            else if (target > matrix[mid][m-1]){
                low = mid+1;
            }
            else{
                is_row_found  = true;
                target_row = mid;
                break;
            }
        }

        if(is_row_found){
            // Binary search within the identified row
            low = 0;
            high = m-1;

            while(low <= high){
                int mid = low + (high-low)/2;

                if(target > matrix[target_row][mid]){
                    low = mid+1;
                }
                else if(target < matrix[target_row][mid]){
                    high = mid-1;
                }
                else{
                    return true; // Target found
                }
            }
        }
        return false; // Target not found
    }
};
