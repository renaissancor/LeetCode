class Solution {
public:
    string removeStars(string s) {
        string str = ""; 

        for(char &c: s)
            c == '*' ? str.pop_back() : str.push_back(c); 

        return str;         
    }
};