// Comments by ChatGPT
// This function counts the number of subsets where consecutive elements differ by exactly 1.
// It sorts the array and increments the count whenever the current element is not consecutive to the previous.
class Solution {
public:
    int numOfSubset(vector<int> &arr) {
        // Get the size of the array
        int n = arr.size();
        // Sort the array to make consecutive elements adjacent
        sort(arr.begin(), arr.end());
        
        int count = 1;  // At least one subset exists
        for(int i = 1; i < n; i++){
            // Increment count when elements are not consecutive
            if(arr[i-1] != arr[i]-1){
                count++;
            }
        }
        return count;
    }
};
