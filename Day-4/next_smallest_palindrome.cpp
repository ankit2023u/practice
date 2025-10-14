// User function template for C++
class Solution {
  public:
    // Helper function to check if the newly formed palindrome is greater than original number
    bool is_great(int nums[], vector<int> &ans) {
        for (int i = 0; i < ans.size(); i++) {
            if (nums[i] > ans[i]) return false; // original number is greater
            if (nums[i] < ans[i]) return true;  // palindrome is greater
        }
        return false; // equal
    }

    vector<int> generateNextPalindrome(int num[], int n) {
        // Step 1: Check if all digits are 9
        bool all_nine = true;
        vector<int> answer(n, 0);

        // Copy the first half of num to answer and check for non-nine digits
        for (int i = 0; i < (n + 1) / 2; i++) {
            if (num[i] != 9) all_nine = false;
            answer[i] = num[i];
        }

        // Mirror the first half to the second half to make it a palindrome
        for (int i = (n + 1) / 2; i < n; i++) {
            answer[i] = answer[n - i - 1];
        }

        // Step 2: If the mirrored palindrome is already greater than original, return it
        if (is_great(num, answer)) {
            return answer;
        }

        // Step 3: If not all digits are 9, increment the middle digit(s) and mirror again
        if (!all_nine) {
            int carry = 0;
            int i = (n + 1) / 2 - 1; // start from the middle digit

            // Increment the middle and propagate carry if needed
            do {
                answer[i] += 1;
                if (answer[i] > 9) {
                    answer[i] %= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                i--;
            } while (carry && i >= 0);

            // Mirror the updated first half to second half
            for (int i = (n + 1) / 2; i < n; i++) {
                answer[i] = answer[n - i - 1];
            }
        } 
        // Step 4: If all digits were 9, the next palindrome is 100...001
        else {
            answer[0] = 1;
            for (int i = 1; i < n; i++) answer[i] = 0;
            answer.push_back(1); // increase length by 1
        }

        // Step 5: Return the next palindrome
        return answer;
    }
};
