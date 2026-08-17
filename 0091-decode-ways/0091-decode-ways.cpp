class Solution {
public:

    int rec(string &s, int level,vector<int> &dp){

        int n = s.size();
        // base case
        if(level == n){
            return 1;
        }

        if(s[level]=='0'){
            return 0;
        }

        //if already exist

        if(dp[level]!=-1){
            return dp[level];
        }

        // Choice 1:
        // take one character

        int choice1 = rec(s,level+1,dp);
        // Choice 2:
        // take two characters IF they form 10...26
        int choice2 = 0;
        if(level+1<n){
            int twodigit = (s[level]-'0')*10+(s[level+1]-'0');
            if(twodigit>=10 && twodigit<=26){
                choice2 = rec(s,level+2,dp);
            }
        }
        int ans = 0;
        ans = choice1 + choice2;

        return dp[level]=ans;

    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return rec(s,0,dp);
    }
};