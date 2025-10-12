// Comments by ChatGPT
// This function counts the number of triplets with a sum less than the given value.
// It uses sorting and a two-pointer approach to efficiently find valid triplets.
class Solution {

public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        long long count = 0;
        // Sort the array to enable two-pointer traversal
        sort(arr, arr+n);

        // Fix one element and use two pointers for the other two
        for(int k = 0; k <= n-3; k++){
            int i = k+1;    // Start pointer
            int j = n-1;    // End pointer

            // Move pointers to find all valid pairs with arr[k]
            while(i < j){
                long long val = arr[i] + arr[j] + arr[k];
                if(val < sum){
                    count += j-i;  // All pairs between i and j are valid
                    i++;
                }
                else{
                    j--;  // Reduce sum by moving end pointer left
                }
            }
        }
        return count;
    }
};
