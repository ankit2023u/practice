string Solution::solve(string A, int B) {
    // Function to remove all consecutive characters that appear exactly B times
    
    int n = A.size(); // Length of the string
    
    int j = 0; // Pointer to traverse the string
    int i = 0; // Start index of current sequence of identical characters
    
    // Step 1: Traverse the string
    while (j < n) {
        // Step 1a: Move j forward while characters at i and j are the same
        while (A[i] == A[j]) {
            j++;
        }
        
        // Step 2: Check if the sequence length equals B
        if (j - i == B) {
            // If yes, erase this sequence from the string
            A.erase(i, B);
            
            // Reset j to i because string has shortened
            j = i;
            
            // Update length of string
            n -= B;
        }
        else {
            // Step 3: If sequence length is not B, move i to start of next sequence
            i = j;
        }
    }
    
    // Step 4: Return the modified string
    return A;
}
