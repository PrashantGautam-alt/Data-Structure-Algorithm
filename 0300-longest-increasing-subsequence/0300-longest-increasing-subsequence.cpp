class Solution {
public:

    vector<vector<int>> dp;

    int rec(vector<int>& nums, int level, int prev) {
        // base case
        if (level == nums.size())
            return 0;

        // cache check
        if (dp[level][prev+1] != -1)
            return dp[level][prev+1];

        int ans = rec(nums, level + 1, prev);



        // compute

        // for (int prev_taken = 0; prev_taken < level; prev_taken++) {
        //     if (arr[prev_taken] < arr[level]) {
        //         ans = max(ans, 1 + rec(prev_taken));
        //     }
        // }

        if (prev == -1 || nums[level] > nums[prev]) {
            ans = max(ans, 1 + rec(nums, level + 1, level));
        }
        // save and return
        return dp[level][prev + 1] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // prev can be -1, so we use prev + 1 as the index
        dp.assign(n, vector<int>(n + 1, -1));

        return rec(nums, 0, -1);
    }
};