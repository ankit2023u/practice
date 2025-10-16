// User function template for C++
class Solution {
  public:
    string removeDuplicates(string &s) {
        // Function to remove duplicate characters from a string 
        // while preserving the order of their first occurrence
        
        int n = s.size();           // Length of the input string
        string answer = "";         // Result string to store unique characters
        set<char> distinct;         // Set to keep track of already seen characters
        
        // Traverse each character in the string
        for(int i = 0; i < n; i++){
            // If the character is not already present in the set,
            // add it to the result and mark it as seen
            if(distinct.find(s[i]) == distinct.end()){
                answer += s[i];      // Add character to the result
                distinct.insert(s[i]); // Mark it as seen
            }
        }
        
        // Return the string with duplicates removed
        return answer;
    }
};
