class Solution {
public:

    int rec(vector<int>& prices, int level, int bought, vector<vector<int>>& dp){
        int n = prices.size();
        if(level == n){
            return 0;
        }

        if(dp[level][bought]!=-1){
            return dp[level][bought];
        }

        int ans;

        if(bought==0){
            int skip = rec(prices, level+1, 0, dp);
            int buy = -prices[level] + rec(prices, level+1, 1, dp);

            ans = max(skip, buy);
        }
        else{
            int hold = rec(prices, level+1, 1, dp);
            int sell = prices[level];

            ans = max(hold, sell);
        }

        return dp[level][bought] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return rec(prices, 0, 0, dp)
    }
};