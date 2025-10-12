// Comments by ChatGPT
// This function calculates the total fine for cars based on the parity of the date and car numbers.
// If a car's number has a different parity than the date, its corresponding fine is added to the total.
// Returns the sum of fines as a long long int.

class Solution {
  public:
    long long int totalFine(int date, vector<int> &car, vector<int> &fine) {
        // Get the number of cars
        int n = car.size();
        long long int total = 0;

        // Iterate over each car and check parity with the date
        for(int i = 0; i < n; i++){
            if(car[i]%2 != date%2){
                total += 1ll*fine[i]; // Add fine if parity doesn't match
            }
        }

        // Return the total fine
        return total;
    }
};
