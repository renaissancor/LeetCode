class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0; 
        int n = isConnected.size(); 
        queue<int> que; 

        bool *visited = new bool[n]; 
        for(int i=0; i<n; ++i) visited[i] = false; 

        while(true) {
            int idx = -1; 
            for(int i=0; i<n; ++i) {
                if(visited[i] == false) {
                    idx = i; 
                    break; 
                }
            } 
            if(idx == -1) break; // This should happen someday 
            else ++ans; 

            visited[idx] = true; 
            que.push(idx); 
            while(!que.empty()) {
                idx = que.front(); 
                for(int i = 0; i < n; ++i) {
                    if(i == idx) continue;
                    if(isConnected[idx][i]) {
                        if(visited[i] == false){
                            visited[i] = true; 
                            que.push(i); 
                        } 
                    }
                }
                que.pop(); 
            }
        }
        delete [] visited; 
        return ans; 
    }
};