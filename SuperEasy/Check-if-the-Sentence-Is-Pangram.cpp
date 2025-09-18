class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> exist(26, false); 
        for (char &c : sentence) {
            if(c - 'a' < 26) exist[c - 'a'] = true; 
        }
        for (size_t i = 0; i < 26; ++i) {
            if (exist[i] == false) return false;  
        }
        return true; 

    }
};