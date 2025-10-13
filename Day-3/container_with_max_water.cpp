class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // Function to calculate the maximum amount of water a container can store
        int n = arr.size();  // Get the total number of elements (heights)
        int i = 0;           // Left pointer
        int j = n - 1;       // Right pointer
        
        int max_water = 0;   // Variable to store the maximum water found
        
        // Two-pointer approach
        while (i < j) {
            // Height of container is determined by the shorter line
            int h = min(arr[i], arr[j]);
            // Width is the distance between the two lines
            int w = j - i;
            
            // Calculate the water stored and update maximum if larger
            max_water = max(h * w, max_water);
            
            // Move the pointer pointing to the shorter line inward
            // (to potentially find a taller line for more water)
            if (arr[i] >= arr[j]) {
                j--;
            } else {
                i++;
            }
        }
        
        // Return the maximum water that can be contained
        return max_water;
    }
};
