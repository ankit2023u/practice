// Comments by ChatGPT
// This function performs a binary sort on an array containing only 0s and 1s.
// It counts the number of 0s in the array and overwrites the array:
// first 'count' elements are 0, and the rest are 1.

class Solution {
  public:
    void binSort(vector<int> &arr) {
        // Get the size of the array
        int n = arr.size();
        int count = 0;

        // Count the number of 0s and set all elements to 0 temporarily
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                count++;
            }
            else{
                arr[i] = 0;
            }
        }
        
        // Fill the remaining elements with 1
        for(int i = count; i < n; i++) arr[i] = 1;
    }
};
