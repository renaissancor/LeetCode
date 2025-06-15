class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
            
        vector<vector<pair<int,bool>>> adj(n);

        for(auto iter : connections) {
            adj[iter[0]].push_back({iter[1], true});  // 정방향 
            adj[iter[1]].push_back({iter[0], false}); // 역방향 
        }

        vector<bool> visited(n, false);
        
        int count = 0; 
        stack<int> stk; 
        stk.push(0); 
        visited[0] = true; 

        while(stk.empty() == false) {
            int now = stk.top(); 
            stk.pop(); 

            for(auto& [next, needReverse] : adj[now]) {
                if(!visited[next]) {
                    visited[next] = true;
                    stk.push(next);
                    if(needReverse) {  // true면 count++
                        count++;
                    }
                }
            }
        }
        return count; 
    }
};