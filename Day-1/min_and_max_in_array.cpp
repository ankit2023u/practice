class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            maxi = max(maxi, arr[i]);
            mini = min(mini, arr[i]);
        }
        
        return {mini, maxi};
    }
};
