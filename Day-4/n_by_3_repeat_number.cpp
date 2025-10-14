int Solution::repeatedNumber(const vector<int> &A) {
    
    int n = A.size();
    
    // Variables to store two potential candidates
    int c1 = 0;
    int c2 = 0;

    // Their corresponding counts
    int count1 = 0;
    int count2 = 0;

    // Step 1: Find two candidates that could possibly appear more than n/3 times
    for (int i = 0; i < n; i++) {
        if (A[i] == c1) {
            // Same as first candidate → increment count
            count1++;
        }
        else if (A[i] == c2) {
            // Same as second candidate → increment count
            count2++;
        }
        else if (count1 == 0) {
            // First candidate slot empty → take current element
            c1 = A[i];
            count1 = 1;
        }
        else if (count2 == 0) {
            // Second candidate slot empty → take current element
            c2 = A[i];
            count2 = 1;
        }
        else {
            // Both candidates occupied and current element is different
            // Decrease both counts (vote out)
            count1--;
            count2--;
        }
    }

    // Step 2: Verify the two candidates by counting actual occurrences
    int real_count1 = 0;
    int real_count2 = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] == c1) real_count1++;
        if (A[i] == c2) real_count2++;
    }

    // Step 3: Check which candidate (if any) occurs more than n/3 times
    if (real_count1 > n / 3) return c1;
    if (real_count2 > n / 3) return c2;

    // If no such element exists
    return -1;
}
