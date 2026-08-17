class Solution {
public:
    int rec(int i, int j, int n, int m, string &text1, string &text2, vector<vector<int>> &dp){
        

        //pruning

        //base case
        if(i>=n || j>= m){
            return 0;
        }

        // if already computed
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // compute

        int ans = 0;

        ans = max(ans, rec(i,j+1,n,m,text1,text2,dp));
        ans = max(ans, rec(i+1,j,n,m,text1,text2,dp));

        if(text1[i]==text2[j]){
            ans = max(ans, 1 + rec(i+1,j+1,n,m,text1,text2,dp));
        }

        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return rec(0,0,n,m,text1,text2,dp);
    }
};