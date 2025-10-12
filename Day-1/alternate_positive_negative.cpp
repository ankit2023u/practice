// Comments by ChatGPT
// This function rearranges the array 'arr' such that positive and negative numbers are placed alternately.
// If either positives or negatives run out, the remaining elements are appended at the end in their original order.
// It uses separate vectors to store positive and negative numbers and then merges them back into 'arr'.

// User function template for C++ 
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // Get the size of the array
        int s = arr.size();
        vector<int> neg; // Store negative numbers
        vector<int> pos; // Store positive numbers
        
        // Separate positives and negatives
        for(int i = 0; i < s; i++){
            if(arr[i] < 0){
                neg.push_back(arr[i]);
            }
            else{
                pos.push_back(arr[i]);
            }
        }
        
        int i = 0;          // Index for pos/neg vectors
        int k = 0;          // Index for original array
        int p = pos.size(); // Number of positive elements
        int n = neg.size(); // Number of negative elements

        // Place positive and negative elements alternately
        while(i < n && i < p){
            arr[k] = pos[i];
            arr[k+1] = neg[i];
            i++;
            k += 2;
        }
        
        // Append remaining negative elements if any
        while(i < n){
            arr[k] = neg[i];
            i++;
            k++;
        }
        
        // Append remaining positive elements if any
        while(i < p){
            arr[k] = pos[i];
            i++;
            k++;
        }
    }
};
