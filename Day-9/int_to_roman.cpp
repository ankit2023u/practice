string Solution::intToRoman(int A) {
    // Copy the input integer to a local variable for manipulation
    int num = A;

    // Predefined Roman numeral values and their corresponding integer equivalents
    vector<int> values = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    };

    // Corresponding Roman symbols aligned with 'values'
    vector<string> symbols = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    };

    // Resultant Roman numeral string
    string ans = "";

    // Loop through each value-symbol pair
    for (int i = 0; i < values.size(); i++) {
        // While the current value can be subtracted from the number,
        // append its Roman equivalent and reduce the number
        while (num >= values[i]) {
            num -= values[i];       // Subtract the value
            ans += symbols[i];      // Append corresponding Roman symbol
        }
    }

    // Return the constructed Roman numeral representation
    return ans;
}
