class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans = 0; 

        unordered_map<char, size_t> uset;

        size_t j = 0; 
        for(size_t i = 0; i < s.size(); ++i) {
            if(uset.count(s[i])) {
                j = max(j, uset[s[i]] + 1); 
            }
            uset[s[i]] = i; // If no exist input else overwrite 
            ans = ans > i - j + 1 ? ans : i - j + 1; 
        }
        return ans; 
    }
};