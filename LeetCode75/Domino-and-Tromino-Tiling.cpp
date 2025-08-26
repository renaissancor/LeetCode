class Solution {
private:
    const int modulo = 1000000007;
public:
    int numTilings(int n) {
        if (n < 3) return n; 
        if (n == 3) return 5; 

        vector<int> dp(n, 0); 

        dp[0] = 1; 
        dp[1] = 2; 
        dp[2] = 5; 

        for(int i = 3; i < n; ++i) {
            dp[i] = (((dp[i - 1] * 2) % modulo) + dp[i - 3]) % modulo; 
        }
        
        return dp[n - 1] % modulo ; 
    }
};