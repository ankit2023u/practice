class Solution {
  public:
    // Returns index of the minimum element in arr starting from index s.
    int find_min_index(vector<int> &arr, int n, int s){
        int mini = s; // assume current start is minimum
        for(int i = s + 1; i < n; i++){
            if(arr[i] < arr[mini]){ 
                mini = i; // update when a smaller element is found
            }
        }
        return mini;
    }

    // Performs selection sort in-place.
    void selectionSort(vector<int> &arr) {
        int n = arr.size();
        for(int i = 0; i < n - 1; i++){
            // find index of smallest element from i to end
            int mini = find_min_index(arr, n, i);
            swap(arr[i], arr[mini]); // bring smallest to sorted position
        }
    }
};
