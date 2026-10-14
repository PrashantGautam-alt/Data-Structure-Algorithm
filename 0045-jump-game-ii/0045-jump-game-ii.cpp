class Solution {
public:
    int rec(vector<int>& nums, int level, vector<int>& dp){
        int n = nums.size();
        //base case
        if(level>=n-1){
            return 0;
        }
        //cached
        if(dp[level]!=-1){
            return dp[level];
        }
        int ans = 1e9;

        //compute
        for(int j = 1; j <= nums[level] && level + j < n; j++){
            int jumps = rec(nums, level + j, dp);

            if (jumps != 1e9) {
                ans = min(ans, 1 + jumps);
            }
        }

        //store and return
        return dp[level]=ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        int ans = rec(nums,0,dp);
        return ans;
    }
};