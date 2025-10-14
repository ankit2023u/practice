class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // Function to find the maximum circular subarray sum
        int n = arr.size();
       
        // Step 1: Compute total sum of the array
        int total_sum = 0;
        for (int i = 0; i < n; i++) total_sum += arr[i];
       
        // Step 2: Find the minimum subarray sum using Kadane’s algorithm (for min)
        int min_sum = arr[0];
        int sum = arr[0];
        for (int i = 1; i < n; i++) {
            // either start new subarray at arr[i] or extend previous one
            sum = min(arr[i], sum + arr[i]);
            min_sum = min(min_sum, sum);
        }
       
        // Step 3: Find the maximum subarray sum using Kadane’s algorithm (for max)
        int max_sum = arr[0];
        sum = arr[0];
        for (int i = 1; i < n; i++) {
            // either start new subarray at arr[i] or extend previous one
            sum = max(arr[i], sum + arr[i]);
            max_sum = max(max_sum, sum);
        }
       
        // Step 4: If all elements are negative, max_sum is the answer
        if (max_sum < 0) return max_sum;
       
        // Step 5: Return the maximum of normal and circular cases
        // Circular case = total_sum - min_sum
        return max(max_sum, total_sum - min_sum);
    }
};
