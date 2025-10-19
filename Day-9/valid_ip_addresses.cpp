//BRUTE FORCE O(n^4) 
vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> answer;
    int n = A.size();
    
    if(n > 12) return answer;
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                for(int l = k+1; l < n; l++){
                    bool poss = true;
                    vector<string> val = {A.substr(i, j-i), A.substr(j, k-j), A.substr(k, l-k), A.substr(l, n-l)};
                    
                    for(int p = 0; p < 4; p++){
                        int sz = val[p].size();
                        
                        if(sz > 3) poss = false;
                        else if(sz > 1 && val[p][0] == '0') poss = false;
                        else if(stoi(val[p]) > 255) poss = false;
                    }
                    if(!(poss)) continue;
                    
                    string ans = val[0] + "." + val[1] + "." + val[2] + "." + val[3];
                    if(ans.size() == n+3) answer.push_back(ans);
                }
            }
        }
    }
    return answer;
    
}

// BETTER O(n^3) 
vector<string> Solution::restoreIpAddresses(string A) {
    // Function to generate all possible valid IP addresses from a string of digits
    
    vector<string> answer; // Stores all valid IP addresses
    int n = A.size();
    
    // Step 1: An IP address has 4 parts, each up to 3 digits → max 12 digits total
    if (n > 12) return answer;
    
    // Step 2: Try all possible split points for 3 dots (brute-force)
    // i, j, k represent the indices where dots will be placed
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                
                bool poss = true; // Flag to track if current 4-part split is valid
                
                // Step 3: Split A into 4 segments based on i, j, k
                // Example: A = "25525511135"
                // i = 3, j = 6, k = 9 → parts = {"255", "255", "111", "35"}
                vector<string> val = {
                    A.substr(0, i - 0),   // First segment: from 0 to i-1
                    A.substr(i, j - i),   // Second segment: from i to j-1
                    A.substr(j, k - j),   // Third segment: from j to k-1
                    A.substr(k, n - k)    // Fourth segment: from k to end
                };
                
                // Step 4: Validate each segment according to IP address rules
                for (int p = 0; p < 4; p++) {
                    int sz = val[p].size();
                    
                    // Invalid if:
                    // - Segment longer than 3 digits
                    // - Leading zero in multi-digit number (e.g., "01", "00")
                    // - Numeric value > 255
                    if (sz > 3) poss = false;
                    else if (sz > 1 && val[p][0] == '0') poss = false;
                    else if (stoi(val[p]) > 255) poss = false;
                }
                
                // If any segment invalid, skip this split
                if (!poss) continue;
                
                // Step 5: Construct IP address by joining segments with dots
                string ans = val[0] + "." + val[1] + "." + val[2] + "." + val[3];
                
                // Check that final string length matches (accounts for 3 dots)
                if (ans.size() == n + 3)
                    answer.push_back(ans);
            }
        }
    }

    // Step 6: Return all valid IP addresses found
    return answer;
}
