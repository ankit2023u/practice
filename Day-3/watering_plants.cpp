class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        // Function to calculate total steps required to water all plants in order

        int n = plants.size();  // Number of plants

        int req = 0;            // Current water used (amount poured so far)
        int steps = 0;          // Total steps taken by the gardener

        // Step 1: Traverse through each plant in order
        for (int i = 0; i < n;) {
            // If current watering can has enough water for plant i
            if (req + plants[i] <= capacity) {
                req += plants[i];  // Use water for this plant
                i++;               // Move to next plant
                steps++;           // Step forward to next plant
            }
            else {
                // Not enough water → need to return to river and refill
                req = 0;           // Reset water used (refilled to full)
