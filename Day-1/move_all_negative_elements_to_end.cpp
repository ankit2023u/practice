// Comments by ChatGPT
// This function segregates positive and negative elements in the array 'arr'.
// All non-negative elements are placed first, followed by negative elements, preserving their relative order.
// Uses an auxiliary vector 'result' to store the rearranged elements and then moves it back to 'arr'.

class Solution {
public:
    void segregateElements(vector<int>& arr) {
        // Create a temporary vector to store rearranged elements
        vector<int> result;
        result.reserve(arr.size());

        // Append all non-negative elements first
        for (int x : arr) {
            if (x >= 0)
                result.push_back(x);
        }

        // Append all negative elements afterwards
        for (int x : arr) {
            if (x < 0)
                result.push_back(x);
        }

        // Move the rearranged result back to the original array
        arr = move(result);
    }
};
