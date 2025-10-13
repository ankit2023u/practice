class Solution {
public:
    int countPrimes(int n) {
        // Function to count all prime numbers less than n

        // Step 1: Initialize a boolean array "prime"
        // prime[i] = true means i is considered prime initially
        vector<bool> prime(n, true);

        int i = 2;      // Start from the first prime number
        int count = 0;  // To store the number of primes found

        // Step 2: Sieve of Eratosthenes algorithm
        while (i < n) {
            if (prime[i]) {
                count++;  // i is prime, increment count

                // Step 3: Mark all multiples of i as non-prime
                long long num = 1ll * i * i;  // Start from i^2 to avoid redundant work
                while (num < n) {
                    prime[num] = false;  // Mark multiple as not prime
                    num += i;            // Move to next multiple
                }
            }
            i++;  // Move to next number
        }

        // Step 4: Return the total number of primes found
        return count;
    }
};
