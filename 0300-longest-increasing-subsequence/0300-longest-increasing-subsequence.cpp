class Solution {
public:
    int rec(int level, int last_taken, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        //base case
        if(level==n){
            return 0;
        }

        // take if last_taken < x[level]
        // don't take it last_taken >= x[level]

        //already calculated
        if(dp[level][last_taken+1]!=-1){
            return dp[level][last_taken+1];
        }

        int notTake = rec(level + 1, last_taken, nums,dp);

        int take = 0;
        if(last_taken==-1 || nums[level]>nums[last_taken]){
            take = 1 + rec(level+1,level,nums,dp);
        } 
        return dp[level][last_taken+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return rec(0,-1,nums,dp);
        
    }
};