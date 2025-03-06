class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        const int n = grid.size(); 

        unordered_map<string, int> rowMap;

        for (int i = 0; i < n; ++i) {
            string rowStr = ""; 
            for(int j=0; j<n; j++){
                rowStr += to_string(grid[i][j])+' '; 
            }
            rowMap[rowStr]++; 
        }

        int ans = 0; 

        for (int i = 0; i < n; ++i) {
            string colStr = ""; 
            for(int j=0; j<n; j++){
                colStr += to_string(grid[j][i])+' '; 
            }
            
            if(rowMap.find(colStr)!=rowMap.end()){
                ans+=rowMap[colStr]; 
            } 
        }

        return ans;
    }
};