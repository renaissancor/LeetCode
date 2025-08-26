class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int n = prices.size(); 
        if (n < 2) return 0; 

        int hold = -prices[0]; 
        int sell = 0; 

        for (int i = 1; i < n; ++i) 
        {
            hold = max(hold, sell - prices[i]);
            sell = max(sell, hold + prices[i] - fee);  
        }

        return sell < 0 ? 0 : sell; 
    }
};