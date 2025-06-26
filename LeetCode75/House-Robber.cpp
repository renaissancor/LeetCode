class Solution {
public:
    int rob(vector<int>& nums) {
        unsigned int n = nums.size();
        vector<int> dp(n); 

        dp[0] = nums[0]; 
        if(n == 1) return dp[0];  
        dp[1] = nums[1]; 
        if(n == 2) return max(dp[0], dp[1]); 

        for(unsigned int i = 2; i < n; ++i) {
            dp[i] = 0; // clear value 
            for(unsigned int j = 0; j < i - 1; ++j) {
                dp[i] = max(dp[j] + nums[i], dp[i]); 
            }

            dp[i] = max(dp[i], dp[i-1]); 
        }

        return dp[n-1]; 
    }
};