// Comments by ChatGPT
// This function removes duplicates from a sorted array 'arr'.
// It iterates through the array and adds elements to 'answer' only if they are different from the previous element.
// Returns a vector containing unique elements in the same order.

class Solution {
  public:
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        int n = arr.size();
        
        // Initialize the answer vector with the first element
        vector<int> answer;
        answer.push_back(arr[0]);
        
        // Traverse the array starting from the second element
        for(int i = 1; i < n; i++){
            if(arr[i] == arr[i-1]) continue; // Skip duplicates
            answer.push_back(arr[i]);        // Add unique elements
        }

        // Return the vector with duplicates removed
        return answer;
    }
};
