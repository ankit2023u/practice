int Solution::power(string A) {
    // Base cases
    if (A == "1") return 0;   // 1 is not a power of 2
    if (A == "0") return 1;   // 0 is not valid, so return 1 (probably intended as false)

    string q = A;  // Copy of input number (as string)

    // Keep dividing the number by 2 until it becomes "1"
    while (q != "1") {
        int sz = q.size();

        // If the last digit is odd, number is not divisible by 2 → not a power of 2
        if ((q[sz - 1] - '0') % 2) return 0;

        int num = q[0] - '0';  // Current partial number for division
        string nq = "";        // Will hold the result of q / 2 (as string)

        // Perform manual string-based division by 2
        for (int i = 1; i < sz; i++) {
            if (num > 1) {
                // If current number ≥ 2, append quotient digit
                nq += to_string(num / 2);
                num %= 2;  // Carry remainder
            } else {
                // Handle cases where quotient digit is 0 (only skip for the very first digit)
                if (i != 1) {
                    nq += "0";
                }
            }

            // Bring down the next digit
            num *= 10;
            num += (q[i] - '0');
        }

        // After loop, handle the final division result
        if (num % 2) {
            // If remainder is 1 → not divisible cleanly by 2 → not a power of 2
            return 0;
        } else {
            nq += to_string(num / 2);  // Append final digit of quotient
        }

        // Replace q with the divided result
        q = nq;
    }

    // If we successfully reach "1", it was a power of 2
    return q == "1";
}
