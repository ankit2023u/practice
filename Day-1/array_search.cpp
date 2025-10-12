// Comments by ChatGPT
// This is a simple linear search implementation in C++.
// The function 'search' takes a vector 'arr' and an integer 'x'.
// It iterates through the vector to find the first occurrence of 'x'.
// If 'x' is found, it returns its index; otherwise, it returns -1.

class Solution {
  public:
    int search(vector<int>& arr, int x) {
        // Get the size of the array
        int n = arr.size();

        // Iterate through each element in the array
        for(int i = 0; i < n; i++){
            // If the current element matches x, return its index
            if(arr[i] == x){
                return i;
            }
        }

        // If x is not found in the array, return -1
        return -1;
    }
};
