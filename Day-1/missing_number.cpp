// Comments by ChatGPT
// This function finds the missing number in an array containing numbers from 1 to n with one missing.
// It calculates the sum of all elements in 'arr' and subtracts it from the expected sum of numbers from 1 to n.
// Uses long long to prevent integer overflow.

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();
        
        // Calculate the sum of array elements
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += 1ll * arr[i]; // Ensure multiplication as long long
        }
        
        n = n+1; // Total number of elements including the missing one
        
        // Calculate the expected sum of first n natural numbers
        long long n_sum = (1ll*n*(n+1))/2;
        
        // The missing number is the difference between expected sum and actual sum
        return n_sum - sum;
    }
};
