class Solution {
public:
    string longestPalindrome(string s) {
        const size_t n = s.size();
        string ans;
        ans.push_back(s[0]);  
        for (size_t k = 0; k < n; ++k)
        {
            size_t i = k, j = k;
            while(j < n && s[i] == s[j])
            {
                if (j - i + 1 > ans.size()) ans = s.substr(i, j - i + 1);
                if (i == 0) break;
                --i, ++j;
            }

            i = k, j = k + 1;
            while (j < n && s[i] == s[j]) {
                if (j - i + 1 > ans.size()) ans = s.substr(i, j - i + 1);
                if (i == 0) break;
                --i, ++j;
            }
        }
        return ans;
    }
};
