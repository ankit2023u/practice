// Comments by ChatGPT
// This function sorts an array 'arr' consisting of only 0s, 1s, and 2s.
// It first counts the occurrences of each element using a 'counts' array.
// Then, it overwrites the original array with 0s, 1s, and 2s according to their counts.

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();
        vector<int> counts(3, 0); // To store counts of 0, 1, 2
        
        // Count occurrences of each element
        for(int i = 0; i < n; i++){
            counts[arr[i]]++;
        }
        
        // Overwrite the original array with sorted elements
        int i = 0;
        int k = 0;
        while(i < 3){
            while(counts[i]--){
                arr[k] = i;
                k++;
            }
            i++;
        }
    }
};
