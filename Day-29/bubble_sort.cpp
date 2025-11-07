// User function template for C++

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();

        // Outer loop for each pass
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;  // Flag to check if any swap occurred

            // Inner loop for comparing adjacent elements
            // After each pass, the largest element gets pushed to the end
            for (int j = 0; j < n - 1 - i; j++) {
                // Swap if elements are in wrong order
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;  // Mark that a swap has occurred
                }
            }

            // If no swaps occurred in this pass, the array is already sorted
            if (!swapped) break;
        }
    }
};
