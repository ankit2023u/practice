bool metaStrings(string S1, string S2) {
    // Function to check if two strings are "meta strings"
    // Meta strings are strings that can be made equal by exactly one swap of two characters in one of the strings.

    int n = S1.size();
    int m = S2.size();
    
    // If strings have different lengths, they can’t be meta strings
    if(n != m) return false;
    
    int count = 0;  // Count the number of mismatched positions
    
    // Step 1: Count mismatches between S1 and S2
    for(int i = 0; i < n; i++){
        if(S1[i] != S2[i]) 
            count++;
        
        // More than 2 mismatches means they can’t be made equal with a single swap
        if(count > 2) 
            return false;
    }
    
    // Step 2: If there are exactly 2 mismatched positions,
    // check if both strings contain the same set of characters
    if(count == 2){
        vector<int> freq(26, 0);  // Frequency difference tracker for 'a'–'z'
        
        // Increment for characters in S1 and decrement for S2
        for(int i = 0; i < n; i++){
            freq[S1[i] - 'a']++;
            freq[S2[i] - 'a']--;
        }
        
        // If any character count mismatches, strings aren't anagrams of each other
        for(int i = 0; i < 26; i++){
            if(freq[i]) 
                return false;
        }
        
        // If counts match, they differ only by one valid swap
        return true;
    }
    
    // Step 3: If mismatches are not exactly 2, not meta strings
    return false;
}
