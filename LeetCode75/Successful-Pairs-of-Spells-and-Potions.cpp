class Solution {
    typedef pair<int, int> pii; 
    typedef long long ll; 
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, ll success) {
        const int m =  spells.size(); 
        const int n = potions.size(); 

        vector<pii> s(m);
        
        for (int i = 0; i < m; ++i) s[i] = {i,  spells[i]}; 

        sort(s.begin(), s.end(), 
            [](const pii &a, pii &b)->bool
            { return a.second > b.second; }
        ); 

        sort(potions.begin(), potions.end(), less<int>()); 

        vector<int> ans(m, 0); 
        int i = 0, j = 0; 

        for(i = 0; i < m; ++i) {
            ll spell  = (ll) s[i].second; 
            while (j < n && potions[j] * spell < success) ++j;
            ans[s[i].first] = n - j; 
        }

        return ans; 
    }
};