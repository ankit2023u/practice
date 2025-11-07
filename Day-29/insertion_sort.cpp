// User function template for C++

class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();

        // Start from the second element (index 1) and insert it into the sorted part
        for (int i = 1; i < n; i++) {
            int j = i - 1;      // Index of the last element in the sorted part
            int temp = arr[i];  // Element to be inserted into the correct position

            // Shift elements greater than temp one position ahead
            while (j >= 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }

            // Place temp at its correct sorted position
            arr[j + 1] = temp;
        }
    }
};
