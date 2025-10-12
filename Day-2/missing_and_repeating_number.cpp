// Comments by ChatGPT
// This function finds the duplicate and missing elements in an array containing numbers from 1 to n.
// It uses a boolean vector to track seen numbers.
class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();
        // Boolean vector to track which numbers have been found
        vector <bool> found(n, false);
        
        int duplicate;
        // Identify the duplicate number
        for(int i = 0; i < n; i++){
            if(!(found[arr[i]-1])){
                found[arr[i]-1] = true;  // Mark number as found
            }
            else{
                duplicate = arr[i];  // Number seen before, so it's duplicate
            }
        }
        
        int missing;
        // Identify the missing number
        for(int i = 0; i < n; i++){
            if(!(found[i])){
                missing = i+1;  // Index + 1 gives the missing number
            }
        }
        return {duplicate, missing};
    }
};
