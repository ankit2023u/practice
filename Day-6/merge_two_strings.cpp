string merge(string S1, string S2) {
    // Function to merge two strings alternately character by character
    
    int m = S1.size();  // Length of first string
    int n = S2.size();  // Length of second string
    string comb = "";   // Resultant merged string
    
    int i = 0;
    // Add characters alternately from both strings until one ends
    for(; i < min(m, n); i++){
        comb += S1[i];  // Add from first string
        comb += S2[i];  // Add from second string
    }
    
    // If first string is longer, append the remaining characters
    for(int j = i; j < m; j++){
        comb += S1[j];
    }
    
    // If second string is longer, append the remaining characters
    for(int j = i; j < n; j++){
        comb += S2[j];
    }
    
    // Return the merged string
    return comb;
}
