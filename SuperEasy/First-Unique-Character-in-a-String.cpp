class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> check(26, 0); 

        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a'; 
            check[idx]++;
        }

        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a'; 
            if(check[idx] == 1) return i; 
        }

        return -1; 
    }
};