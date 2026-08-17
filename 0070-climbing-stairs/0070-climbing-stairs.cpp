class Solution {
public:

    int rec(int level, int n, vector<int>& dp){

        //pruning
        if(level>n){
            return 0;
        }
        
        // base case
        if(level==n){
            return 1;
        }

        // already calculated
        if(dp[level]!=-1){
            return dp[level];
        }

        // can move 1 from curr level
        int step1 = rec(level+1, n,dp);
        // can move 2 from curr level
        int step2 = rec(level+2, n,dp);
        //calculate and store
        return dp[level] = step1+step2;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return rec(0,n,dp);
        
    }
};