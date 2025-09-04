class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0; 
        int i_begin = 0; 
        bool minus = false; 
        while(s[i_begin] == ' ') i_begin++; 
        if (s[i_begin] == '-' || s[i_begin] == '+') {
            if(s[i_begin] == '-') minus = true; 
            i_begin++; 
        }
        for (int i = i_begin; i < s.size(); ++i)
        {
            // if(s[i] == ' ') break; 
            if ('0' <= s[i] && s[i] <= '9') {
                ans = ans * 10; 
                if(minus) {
                    ans -= static_cast<long long>(s[i] - '0'); 
                }
                else {
                    ans += static_cast<long long>(s[i] - '0'); 
                }
                
                if(ans > INT_MAX) return INT_MAX; 
                if(ans < INT_MIN) return INT_MIN; 
            }
            else return static_cast<int>(ans); 
        }
        return static_cast<int>(ans); 
    }
};