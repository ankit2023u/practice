#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O setup (optional)
	
	int t, n, x, k;
	cin >> t;  // Number of test cases
	
	while(t--){
	    cin >> n >> x >> k;  
	    // n → number of participants
	    // x → current score of our player
	    // k → number of top participants to remove (or zero out)

	    vector<int> a(n);
	    
	    // Read scores of all participants
	    for(int i = 0; i < n; i++) cin >> a[i];
	    
	    // Sort the scores in ascending order
	    sort(a.begin(), a.end());
	    
	    // Remove (set to 0) the top 'k' participants 
	    // and increase our player's score by 100 for each removal
	    for(int i = n - 1; k--; i--){
	        a[i] = 0;
	        x += 100;
	    }
	    
	    // Initialize player's rank as 1 (best possible)
	    int rank = 1;
	    
	    // Count how many participants still have a score higher than x
	    // For each participant with a higher score, increase rank by 1
	    for(int i = 0; i < n; i++){
	        if(a[i] > x) rank++;
	    }
	    
	    // Output the final rank after removals and score adjustments
	    cout << rank << endl;
	}
}
