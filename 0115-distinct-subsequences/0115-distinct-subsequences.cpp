class Solution {
public:
    int solve(string &s,string &t, int i, int j,vector<vector<int>>&dp){
        if(j==t.size()){
            //reached the end of goal string t , found one valid subsequence
            return 1;
        }
        if(i==s.size()){
            //reached the end of checking string s, havent found a valid subsequence 
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int match=0;
        int notmatch=0;
        if(s[i]==t[j]){
            match=solve(s,t,i+1,j,dp)+solve(s,t,i+1,j+1,dp);
        }else{
            notmatch=solve(s,t,i+1,j,dp);
        }
        return dp[i][j]=match+notmatch;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        return solve(s,t,0,0,dp);
    }
};