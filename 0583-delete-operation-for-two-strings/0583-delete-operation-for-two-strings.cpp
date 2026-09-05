class Solution {
public:
    int LCS(string& word1, string& word2, int i, int j, vector<vector<int>>& dp){
        //base case
        if(i==word1.size() || j==word2.size()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        //case 1. i and j matches
        if(word1[i]==word2[j]){
            return dp[i][j] = 1 + LCS(word1,word2,i+1,j+1,dp);
        }
        // if they dont match then try i+1,j and i,j+1 and take whichever gives the max
        //case 2. 
        return dp[i][j] = max(LCS(word1,word2,i+1,j,dp),LCS(word1,word2,i,j+1,dp));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return n+m - 2* LCS(word1,word2,0,0,dp);
    }
};