// Comments by ChatGPT
// This function rearranges the array such that the elements are placed in max-min form.
// It uses an encoding trick to store two numbers at each index to avoid extra space.
class Solution {
public:
    void rearrange(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();
        // Sort the array to simplify max-min placement
        sort(arr.begin(), arr.end());
        
        int i = 0;        // Pointer for the smallest element
        int j = n-1;      // Pointer for the largest element
        int k = 0;        // Current index
        int M = arr[n-1]+1;  // Modulus to encode two numbers
        
        while(k < n){
            if(k%2){
                // Place the next minimum at odd index using encoding
                arr[k] = (arr[i]%M)*M + arr[k];
                i++;
            }
            else{
                // Place the next maximum at even index using encoding
                arr[k] = (arr[j]%M)*M + arr[k];
                j--;
            }
            k++;
        }
        
        // Decode the values to get the final rearranged array
        for(int i = 0; i < n; i++) arr[i] = arr[i]/M;
    }
};
