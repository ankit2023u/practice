// Comments by ChatGPT
// This function finds the equilibrium point in an array 'arr'.
// An equilibrium point is an index where the sum of elements on its left equals the sum on its right.
// It first calculates the total sum of the array, then iterates to check for the equilibrium point.
// Returns the index of the equilibrium point, or -1 if none exists.

class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // Get the size of the array
        int n = arr.size();
        
        // Calculate the total sum of array elements
        int n_sum = 0;
        for(int i = 0; i < n; i++){
            n_sum += arr[i];
        }
        
        // Initialize left sum
        int sum = 0;
        for(int i = 0; i < n; i++){
            n_sum -= arr[i];         // Right sum after removing current element
            if(sum == n_sum) return i; // Check if left sum equals right sum
            sum += arr[i];           // Update left sum
        }

        // If no equilibrium point found, return -1
        return -1;
    }
};
