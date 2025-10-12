// Comments by ChatGPT
// This function rotates a given array 'arr' by one position to the right.
// The last element of the array moves to the first position, and all other elements shift one position to the right.

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // Get the size of the array
        int n = arr.size();

        // Store the last element since it will be overwritten
        int last = arr[n-1];
        
        // Shift all elements one position to the right
        for(int i = n-1; i > 0; i--){
            arr[i] = arr[i-1];
        }

        // Place the original last element at the first position
        arr[0] = last;
    }
};
