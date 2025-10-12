// Comments by ChatGPT
// This function finds the index of the row with the maximum number of 1s in a binary matrix.
// Each row is sorted (0s followed by 1s), so binary search is used to efficiently find the first 1 in each row.
 
// User function template for C++
class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int r = arr.size();     // Number of rows
        int c = arr[0].size();  // Number of columns
        int max_count = 0;      // Maximum count of 1s found so far
        int index = -1;         // Index of the row with max 1s
        
        // Traverse each row
        for(int i = 0; i < r; i++){
            int low = 0;
            int high = c-1;
            int count = 0;      // Count of 1s in current row
            
            // Binary search to find the first 1 in the current row
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(arr[i][mid]){
                    // Found a 1, so count all elements from mid to end
                    count = c - mid;
                    high = mid - 1;  // Look for an earlier 1
                }
                else{
                    low = mid + 1;   // Move right if 0 found
                }
            }
            
            // Update max_count and index if this row has more 1s
            if(count && count > max_count){
                index = i;
                max_count = count;
            }
        }
        return index;  // Return the index of the row with maximum 1s
    }
};
