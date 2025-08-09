class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const size_t m = grid.size(), n = grid[0].size(); 

        queue<pair<size_t, size_t>> que; 

        bool no_orange = true; 

        for(size_t i = 0; i < m; ++i) {
            for(size_t j = 0; j < n; ++j) {
                if(no_orange && grid[i][j] != 0) no_orange = false;
                if(grid[i][j] == 2) que.push({i, j});
            }
        }

        if(no_orange) return 0; 


        int ans = -1; 

        while(!que.empty()) {
            size_t cycle = que.size(); 
            for(size_t k = 0; k < cycle; ++k) {
                pair<size_t, size_t> cur = que.front(); 
                que.pop(); 
                size_t i = cur.first, j = cur.second; 

                if(0 < i && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 2; 
                    que.push({i - 1, j}); 
                }
                if(0 < j && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2; 
                    que.push({i, j - 1}); 
                }
                if(i < m - 1 && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 2; 
                    que.push({i + 1, j}); 
                }
                if(j < n - 1 && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2; 
                    que.push({i, j + 1}); 
                }
            }
            ++ans; 
        }

        for(size_t i = 0; i < m; ++i) {
            for(size_t j = 0; j < n; ++j) {
                if(grid[i][j] == 1) return -1; 
            }
        }

        return ans; 
    }
}; 