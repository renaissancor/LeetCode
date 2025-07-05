class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> bfs; 
        bfs.push({entrance[0], entrance[1]}); 
        maze[entrance[0]][entrance[1]] = '+';

        const int m = maze.size(); 
        const int n = maze[0].size(); 

        int count = 0; 
        while(!bfs.empty()) {
            size_t bfsz = bfs.size();
            for(size_t i = 0; i < bfsz; ++i) {
                int row = bfs.front().first;
                int col = bfs.front().second;
                bfs.pop();
                if (count != 0) {
                    if (row == 0 || row == m - 1 || col == 0 || col == n - 1) return count;
                }

                if (row > 0 && maze[row - 1][col] == '.') {
                    maze[row - 1][col] = 'v';
                    bfs.push({row - 1, col});
                }
                if (row < m - 1 && maze[row + 1][col] == '.') {
                    maze[row + 1][col] = 'v';
                    bfs.push({row + 1, col});
                }
                if (col > 0 && maze[row][col - 1] == '.') {
                    maze[row][col - 1] = 'v';
                    bfs.push({row, col - 1});
                }
                if (col < n - 1 && maze[row][col + 1] == '.') {
                    maze[row][col + 1] = 'v';
                    bfs.push({row, col + 1});
                }

            }
            ++count;
        }


        return -1; 
    }
};