// User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n) {
        // Function to find the maximum product of any triplet in the array

        // Initialize variables to track global min and max
        long long maxi = INT_MIN;  // maximum value in array
        long long mini = INT_MAX;  // minimum value in array

        // Step 1: Find overall min and max to initialize helper arrays
        for (int i = 0; i < n; i++) {
            maxi = max(arr[i], maxi);
            mini = min(arr[i], mini);
        }

        // maxs[0], maxs[1], maxs[2] will store top 3 maximum values
        vector<long long> maxs(3, mini);
        // mins[0], mins[1], mins[2] will store bottom 3 minimum values
        vector<long long> mins(3, maxi);

        bool zero_exist = false;  // flag to check if 0 exists (not essential but noted)

        // Step 2: Traverse the array and maintain top 3 max and min values
        for (int i = 0; i < n; i++) {
            long long num = arr[i];
            if (num == 0) zero_exist = true;

            // Update the three largest numbers
            if (num > maxs[0]) {
                maxs[2] = maxs[1];
                maxs[1] = maxs[0];
                maxs[0] = num;
            }
            else if (num > maxs[1]) {
                maxs[2] = maxs[1];
                maxs[1] = num;
            }
            else {
                maxs[2] = max(maxs[2], num);
            }

            // Update the three smallest numbers
            if (num < mins[0]) {
                mins[2] = mins[1];
                mins[1] = mins[0];
                mins[0] = num;
            }
            else if (num < mins[1]) {
                mins[2] = mins[1];
                mins[1] = num;
            }
            else {
                mins[2] = min(mins[2], num);
            }
        }

        // Step 3: Compute two possible maximum products:
        // Case 1: Product of top 3 maximum numbers
        long long p1 = maxs[2] * maxs[1] * maxs[0];

        // Case 2: Product of 2 minimum numbers (possibly negative) and 1 maximum number
        long long p2 = mins[1] * mins[0] * maxs[0];

        // Step 4: Return the larger of the two products
        return max(p1, p2);
    }
};
