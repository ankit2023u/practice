#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n;

    // Number of test cases
    cin >> t;

    while (t--) {
        cin >> n;

        // Read array a and compute XOR of all elements
        vector<int> a(n);
        int a_xor = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a_xor ^= a[i];
        }

        // Read array b and compute XOR of all elements
        vector<int> b(n);
        int b_xor = 0;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b_xor ^= b[i];
        }

        // If total XORs differ, someone must win
        bool have_winner = (a_xor != b_xor);

        // Find the last index (from right) where a[i] != b[i]
        // This is the most significant position affecting the game
        int pos = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] != b[i]) {
                pos = i + 1;   // Convert to 1-based index
                break;
            }
        }

        if (have_winner) {
            // If the decisive position is odd, Ajisai controls it
            // If even, Mai controls it
            cout << (pos % 2 ? "Ajisai" : "Mai") << endl;
        } else {
            // Equal XORs → optimal play leads to a tie
            cout << "Tie" << endl;
        }
    }

    return 0;
}
