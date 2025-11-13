class Solution {
public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Get sizes of both arrays.
        int n = a.size();
        int m = b.size();
        
        // If b is larger, it can't be a subset.
        if(m > n) return false;
        
        // Sort both arrays to enable linear two-pointer sweep.
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int i = 0; // pointer for a
        int j = 0; // pointer for b
        
        // Traverse both vectors:
        // Move through 'a' trying to match all elements of 'b'.
        while(j < m && i < n){
            if(a[i] == b[j]){
                // Match found → advance both pointers.
                i++;
                j++;
            } else {
                // No match → move in 'a' to search further.
                i++;
            }
        }
        
        // If 'j' reached the end, all elements in b were matched.
        if(j == m) return true;
        return false;
    }
};
