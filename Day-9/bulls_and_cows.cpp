string Solution::solve(string A, string B) {
    // Function to implement the "Bulls and Cows" game logic:
    // 'A' = correct digit in correct position (bull)
    // 'B' = correct digit in wrong position (cow)
    
    vector<int> freq(10, 0); // Frequency array to count digits (0-9) in A that are not bulls
    
    int n = A.size(); // Length of the strings
    
    int x = 0; // Count of bulls (correct digit at correct position)
    
    // Step 1: Identify bulls and mark them
    for (int i = 0; i < n; i++) {
        if (A[i] == B[i]) {
            x++;        // Increment bull count
            A[i] = '-'; // Mark this position as processed
        } else {
            // Count remaining digits in A for potential cows
            freq[A[i] - '0']++;
        }
    }
    
    int y = 0; // Count of cows (correct digit at wrong position)
    
    // Step 2: Identify cows using frequency array
    for (int i = 0; i < n; i++) {
        if (A[i] != '-' && freq[B[i] - '0']) {
            // If the digit exists in A (and wasn't a bull), count as cow
            freq[B[i] - '0']--;
            y++;
        }
    }
    
    // Step 3: Construct the result string in "xAyB" format
    string ans = to_string(x) + "A" + to_string(y) + "B";
    return ans;
}
