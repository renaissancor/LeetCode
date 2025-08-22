class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; 
        
        vector<string> rows(numRows); 
        enum DIR {UP = -1, DOWN = 1}; 
        DIR dir = DOWN; 
        int row_idx  = 0; 

        for(size_t i = 0; i < s.size(); ++i) {
            const char c = s[i]; 
            rows[row_idx] += c; 
            if (dir == UP && row_idx == 0) dir = DOWN; 
            if (dir == DOWN && row_idx == numRows - 1) dir = UP; 
            row_idx += dir; 
        }

        string ans;
        for (const string& row : rows) ans += row;
        return ans; 
    }
};