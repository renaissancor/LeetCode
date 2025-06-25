class Solution {
private: 
    unordered_map<string, vector<pair<string, double>>> graph;
    double bfs(string src, string dst) {
        if(graph.find(src) == graph.end()) return -1.f; 
        if(graph.find(dst) == graph.end()) return -1.f; 

        queue<pair<string, double>> que; 
        unordered_set<string> visited; 

        que.push({src, 1.0f}); 
        visited.insert(src); 

        while(!que.empty()) {
            auto[cur, tprod] = que.front(); 
            que.pop(); 

            if(cur == dst) return tprod; 
            
            for(auto[next, nprod] : graph[cur]) {
                if(visited.count(next)) continue; 
                visited.insert(next); 
                que.push({next, tprod * nprod});
            }

        }

        return -1.f; 
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        const size_t n = equations.size(); 
        vector<double> ans; 
        if(n != values.size()) return ans; // ERROR 

        for(size_t i = 0; i < n; ++i){
            string src = equations[i][0]; 
            string dst = equations[i][1]; 
            double value = values[i]; 

            graph[src].push_back({dst, value});
            graph[dst].push_back({src, 1.0f / value}); 
        } 

        for(auto query : queries) {
            const string src = query[0]; 
            const string dst = query[1]; 

            if(src == dst && graph.count(src)) ans.push_back(1.f); 
            else ans.push_back(bfs(src, dst)); 
        }
        
        return ans; 
    }
};