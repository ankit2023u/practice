// Comments by ChatGPT
class Solution {
public:
    // Function to partition the array around the range 
    // such that array is divided into three parts.
    void threeWayPartition(vector<int>& arr, int a, int b) {
        // Get the size of the array
        int n = arr.size();
        // Initialize pointers for start and end
        int start = 0;
        int end = n-1;

        // Iterate through the array
        for(int i = 0; i <= end;){
            if(arr[i] < a){
                // Current element less than lower bound, swap to front
                swap(arr[i], arr[start]);
                i++;
                start++;
            }
            else if(arr[i] > b){
                // Current element greater than upper bound, swap to end
                swap(arr[i], arr[end]);
                end--;
            }
            else{
                // Element within range, move forward
                i++;
            }
        }
    }
};
