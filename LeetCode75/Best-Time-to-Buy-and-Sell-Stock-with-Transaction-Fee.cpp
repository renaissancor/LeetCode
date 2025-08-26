class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int n = prices.size(); 
        if (n < 2) return 0; 
        
        vector<int> dpb(n, INT_MIN); // After Buy  Money Left 
        vector<int> dps(n, INT_MIN); // After Sell Money Left 

        dpb[0] = 0 - prices[0]; 
        dpb[1] = 0 - prices[1]; 
        dps[0] = 0; // No Buy No Sell 
        dps[1] = prices[1] + dpb[0] - fee; 

        int b_idx = dpb[0] > dpb[1] ? 0 : 1; // dpb[b_idx] is highest 
        int s_idx = dps[0] > dps[1] ? 0 : 1; // dps[s_idx] is highest 

        for (int i = 2; i < n; ++i) 
        {
            dpb[i] = dps[s_idx] - prices[i]; 
            dps[i] = dpb[b_idx] + prices[i] - fee; 
            if (dpb[i] > dpb[b_idx]) b_idx = i; 
            if (dps[i] > dps[s_idx]) s_idx = i; 
        }

        return dps[s_idx] > 0 ? dps[s_idx] : 0; 
    }
};