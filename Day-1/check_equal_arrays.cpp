// Comments by ChatGPT
// This function checks if two arrays 'a' and 'b' are equal in terms of element counts.
// It uses an unordered_map to count occurrences of each element in 'a'.
// Then, it decrements the count for each element in 'b'.
// If any element in 'b' has a count less than 0, the arrays are not equal.
// Returns true if both arrays contain the same elements with the same frequency.

class Solution {
  public:
    bool checkEqual(vector<int>& a, vector<int>& b) {
        // Get the size of the arrays
        int n = a.size();
        
        // Create a hash map to store element counts
        unordered_map<int, int> hash;
        
        // Count occurrences of elements in array 'a'
        for(int i = 0; i < n; i++){
            hash[a[i]]++;
        }
        
        // Decrement counts based on elements in array 'b'
        for(int i = 0; i < n; i++){
            hash[b[i]]--;
            // If count goes below 0, 'b' has extra or mismatched element
            if(hash[b[i]] < 0) return false;
        }
        
        // All counts matched, arrays are equal
        return true;
    }
};
