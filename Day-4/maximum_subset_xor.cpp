// Function to return the maximum XOR of any subset of the given array
class Solution {
  public:
    int maxSubsetXOR(int arr[], int N) {
        // Step 1: Initialize a vector to store the XOR basis
        vector<int> basis;

        // Step 2: Build the XOR basis
        for (int i = 0; i < N; i++) {
            int x = arr[i];  // Take current element

            // Try to reduce x using existing basis elements
            for (int b : basis) {
                // If XOR-ing with a basis element reduces x, do it
                // This ensures that the basis elements remain independent
                if ((x ^ b) < x) x ^= b;
                if (x == 0) break;  // Already represented by basis, skip
            }

            // If x is non-zero after reduction, it's independent and becomes a new basis element
            if (x != 0) basis.push_back(x);
        }

        // Step 3: Compute the maximum XOR using the basis
        int B = basis.size();
        int max_xor = 0;

        // Greedily XOR basis elements if it increases max_xor
        for (int i = 0; i < B; i++) {
            if ((max_xor ^ basis[i]) > max_xor) 
                max_xor ^= basis[i];
        }

        // Step 4: Return the maximum XOR achievable
        return max_xor;
    }
};
