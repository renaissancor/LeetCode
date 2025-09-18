class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0; 
        for (string &sentence : sentences) {
            bool check = false; // If previous one is  ' '  
            int tmp = 1; 
            for (char &c : sentence) {
                if (c == ' ') {
                    if (check) continue; 
                    else check = true; 
                } else {
                    if (check) {
                        check = false; 
                        tmp++; 
                    }
                }
            }
            ans = max(tmp, ans); 
        }
        return ans; 
    }
};