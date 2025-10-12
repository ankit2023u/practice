// Comments by ChatGPT
// This function finds a continuous subarray in 'arr' whose sum equals 'target'.
// It uses a sliding window approach with two pointers (i, j) to maintain the current subarray sum.
// If such a subarray is found, it returns 1-based indices of start and end; otherwise, returns {-1}.

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // Get the size of the array
        int n = arr.size();

        // Initialize sliding window pointers and sum
        int i = 0;
        int j = 0;
        int sum = 0;
        
        // Expand the window by moving 'j'
        while(j < n){
            sum += arr[j]; // Add current element to sum
            
            // Shrink the window from left if sum exceeds target
            while(i <= j && sum > target){
                sum -= arr[i];
                i++;
            }
            
            // Check if current window sums to target
            if(sum == target) return {i+1, j+1}; // 1-based indices
            
            j++;
        }

        // If no subarray found, return {-1}
        return {-1};
    }
};
