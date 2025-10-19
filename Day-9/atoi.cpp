int Solution::atoi(const string A) {
    // Function to convert a string to an integer (similar to C's atoi)
    // Handles leading spaces, optional '+' or '-', and integer overflow
    
    int n = A.size();
    int sign = 1; // To store the sign of the number (+1 or -1)
    
    int i = 0;
    
    // Step 1: Skip leading whitespace characters
    while (i < n && A[i] == ' ') i++;
    
    // Step 2: Handle optional '+' or '-' sign
    if (i < n && A[i] == '-') {
        sign = -1;
        i++;
    }
    else if (i < n && A[i] == '+') {
        i++;
    }
    
    // Step 3: Extract numeric part of the string
    string number = "";
    while (i < n && A[i] >= '0' && A[i] <= '9') {
        number += A[i];
        i++;
    }

    // Step 4: Convert numeric string to integer value manually
    long long answer = 0;   // Use long long to detect overflow
    int d = number.size();
    long long base = 1;     // Positional multiplier (1, 10, 100, ...)
    
    // Traverse digits from least significant to most significant
    for (int i = d - 1; i >= 0; i--) {
        answer += 1LL * (number[i] - '0') * base;
        base *= 10;
        
        // Step 5: Overflow handling
        if (sign == 1 && answer > INT_MAX) return INT_MAX;
        if (sign == -1 && -answer < INT_MIN) return INT_MIN;
    }
    
    // Step 6: Apply sign and return final integer value
    return (int)(sign * answer);
}
