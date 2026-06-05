class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool>dp(s.size(),false);
        int reachable=0;
        dp[0]=true;
        for(int i=1;i<s.size();i++){
            if(i-minJump>=0&&dp[i-minJump]){
                reachable++;
            }
            if(i-maxJump-1>=0&&dp[i-maxJump-1]){
                reachable--;
            }
            if(reachable>0&&s[i]=='0'){
                dp[i]=true;
            }
        }
        return dp[s.size()-1];
    }
};