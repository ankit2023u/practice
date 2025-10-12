// Comments by ChatGPT
// User function Template for C++
class Solution {
public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Vector to track which leaves are visited
        vector<bool> visited(leaves+1,false);
        visited[0] = true;  // Leaf 0 is considered visited
        
        // Sort the frog jump distances
        sort(frogs, frogs + N);
        
        for(int i = 0; i < N; i++){
            int base = frogs[i];  // Current frog's jump distance
            
            if(base == 1) return 0;  // Frog can reach every leaf
            if(visited[base]) continue;  // Already processed this frog
            if(base > leaves) continue;  // Jump longer than total leaves
            
            // Mark all multiples of base as visited
            while(base <= leaves){
                visited[base] = true;
                base += frogs[i];
            }
        }
        
        int count = 0;
        // Count leaves that remain unvisited
        for(int i = 0; i <= leaves; i++){
            if(!visited[i]) count++;
        }
        return count;
    }
};
