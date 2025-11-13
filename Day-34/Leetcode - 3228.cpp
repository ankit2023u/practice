class Solution {
public:
    int maxOperations(string s) {
        // Tracks whether we have seen a '0' segment while scanning from right.
        // When true, it means zeros are accumulating to the right of current scan point.
        bool last_seen_zero = false;

        // Number of contiguous zeros accumulated while last_seen_zero == true.
        int count = 0;

        // Total operations that can be performed.
        int ops = 0;

        int n = s.size();

        // Scan from right to left because moves push 1s rightwards.
        for(int i = n-1; i >= 0; i--){
            if(!last_seen_zero){
                // We have NOT started a zero-cluster yet.
                if(s[i] == '0'){
                    // Found the first zero from the right → begin a zero-cluster.
                    count++;
                    last_seen_zero = true;
                }
                else{
                    // Encountered a '1' with no active zero-cluster.
                    // This '1' can jump over all collected zeros to the right.
                    ops += count;
                }
            }
            else{
                // We ARE inside a zero-cluster.
                if(s[i] == '1'){
                    // A '1' to the left of the zero-cluster can jump over ALL zeros.
                    ops += count;
                    // After using this '1', the zero-cluster closes.
                    last_seen_zero = false;
                }
                // If s[i] == '0', we stay inside the cluster implicitly.
                // But note: the code does NOT increment "count" here.
                // That is intentional — it treats only the *first* zero encountered
                // as defining the cluster for counting purposes.
            }
        }

        return ops;
    }
};
