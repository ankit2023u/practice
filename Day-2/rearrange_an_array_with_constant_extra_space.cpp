// Comments by ChatGPT
// This function rearranges the array such that arr[i] becomes arr[arr[i]] without using extra space.
// It uses an encoding trick to store both old and new values in a single number.
class Solution {
public:
    void arrange(vector<long long>& arr) {
        // Get the size of the array
        int n = arr.size();

        // Encode both old and new values at each index
        for(int i = 0; i < n; i++){
            arr[i] = n * (arr[arr[i]] % n) + arr[i];
        }
        
        // Decode to get the final rearranged array
        for(int i = 0; i < n; i++){
            arr[i] = arr[i] / n;
        }
    }
};
