// User function template for C++

class Solution {
  public:
    bool check_elements(int arr[], int n, int A, int B) {
        // If A > B, swap them by recursively calling with reversed range
        if (A > B) {
            return check_elements(arr, n, B, A);
        }

        // Use a set to store unique numbers within the given range [A, B]
        set<int> range_nums;

        // Traverse the array
        for (int i = 0; i < n; i++) {
            // If current element lies in the range [A, B], add it to the set
            if (arr[i] >= A && arr[i] <= B) {
                range_nums.insert(arr[i]);
            }
        }

        // If the count of unique elements in range equals (B - A + 1),
        // then all numbers between A and B are present in the array
        return (int)range_nums.size() == (B - A + 1);
    }
};
