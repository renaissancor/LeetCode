class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = ""; 
        size_t siz1 = word1.size();
        size_t siz2 = word2.size(); 
        size_t siz = siz1 > siz2 ? siz1 : siz2; 

        for(size_t ptr=0; ptr<siz; ptr++){
            
            if(ptr < siz1) ans += word1[ptr]; 
            if(ptr < siz2) ans += word2[ptr]; 
        }     

        return ans; 
    }
};