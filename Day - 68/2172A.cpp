#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Store the three AI scores
    vector<int> ais(3);

    // Input the scores
    for (int i = 0; i < 3; i++) {
        cin >> ais[i];
    }

    // Sort scores in non-decreasing order
    sort(ais.begin(), ais.end());

    // If max - min >= 10, judging is inconsistent
    if (ais[2] - ais[0] >= 10) {
        cout << "check again" << endl;
    }
    // Otherwise, print the median score
    else {
        cout << "final " << ais[1] << endl;
    }

    return 0;
}
