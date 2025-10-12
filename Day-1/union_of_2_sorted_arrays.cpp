// Comments by ChatGPT
// This function finds the union of two sorted arrays 'a' and 'b'.
// It merges both arrays into a single sorted array 'c' without duplicates.
// The function uses two pointers to traverse both arrays simultaneously.

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Get sizes of the input arrays
        int m = a.size();
        int n = b.size();
        
        vector<int> c; // Store the union of a and b
        
        int i = 0;
        int j = 0;
        
        // Traverse both arrays simultaneously
        while(i < m && j < n){
            if(a[i] == b[j]){
                // Avoid duplicates in the result
                if(!(c.size() && c.back() == a[i])){
                    c.push_back(a[i]);
                }
                i++;
                j++;
            }
            else if(a[i] < b[j]){
                if(!(c.size() && c.back() == a[i])){
                    c.push_back(a[i]);
                }
                i++;
            }
            else{
                if(!(c.size() && c.back() == b[j])){
                    c.push_back(b[j]);
                }
                j++;
            }
        }
        
        // Add remaining elements from array 'a' if any
        while(i < m){
            if(!(c.size() && c.back() == a[i])){
                c.push_back(a[i]);
            }
            i++;
        }
        
        // Add remaining elements from array 'b' if any
        while(j < n){
            if(!(c.size() && c.back() == b[j])){
                c.push_back(b[j]);
            }
            j++;
        }
        
        // Return the union array
        return c;
    }
};
