class Solution {
public:
    int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp){
        int n = s.size();
        int m = t.size();

        //base case

        if(j == m){
            return 1;
        }
        if(i==n){
            return 0;
        }
        

        //cache
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //if ith elem of s and jth element of t equal then either move both i and j
        // or move only i because it has more characters
        if(s[i]==t[j]){
            return dp[i][j] = solve(s,t,i+1,j+1,dp) + solve(s,t,i+1,j,dp);
        }
        // definetly try i+1 becasue it contains more char
        return dp[i][j] = solve(s,t,i+1,j,dp);
    }
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s,t,0,0,dp);
        
    }
};