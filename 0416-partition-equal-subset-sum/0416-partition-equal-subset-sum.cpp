class Solution {
public:

    int rec(vector<int>& nums, int level, int currSum, int target, 
    vector<vector<int>>& dp){
        //pruning

        //base case
        if(currSum==target){
            return 1;
        }
        if(level == nums.size() || currSum > target){
            return 0;
        }
        // cached

        if(dp[level][currSum]!=-1){
            return dp[level][currSum];
        }
        //cases

        //case1, take the current element

        int take = rec(nums,level+1,currSum+nums[level],target,dp);
        //case2, skip it
        int skip = rec(nums,level+1,currSum,target,dp);
        //save result and return

        return dp[level][currSum] = max(take,skip);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }

        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(target + 1, -1)
        );

        return rec(nums, 0, 0, target, dp);
        
    }
};