class Solution {
public:
    int solve(int pos, string& n,vector<vector<vector<int>>>&dp,bool tight, bool changed,vector<int>&valid){
        if(pos==n.size()){
            return changed;
        }
        if(dp[pos][tight][changed]!=-1){
            return dp[pos][tight][changed];
        }
        int ans=0;
        int limit=(tight==true)?n[pos]-'0':9;
        for(auto d:valid){
            if(d>limit){
                continue;
            }
            bool newtight=(tight&&(limit==d));
            bool newchanged=changed||d==2||d==5||d==6||d==9;
            ans+=solve(pos+1,n,dp,newtight,newchanged,valid);
        }
        return dp[pos][tight][changed]=ans;
    }
    int rotatedDigits(int n) {
        vector<vector<vector<int>>>dp(11,vector<vector<int>>(2,vector<int>(2,-1)));
        string str=to_string(n);
        vector<int>valid={0,1,2,5,6,8,9};
        int res=solve(0,str,dp,true,false,valid);
        return res;
    }
};