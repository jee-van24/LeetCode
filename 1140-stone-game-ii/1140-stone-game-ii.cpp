class Solution {
public:
    int solve(int idx,vector<int>&piles,int player, int limit , vector<int>&psum,vector<vector<vector<int>>>&dp){
        if(idx==piles.size()){
            //cant take no more piles cause empty 
            return 0;
        }
        if(dp[idx][limit][player]!=-1){
            return dp[idx][limit][player];
        }
        int ans;
        if(player==0){
            ans=INT_MIN;
            //alice playing so she will maximise her score
            for(int x=1;x<=2*limit&&idx+x<=piles.size();x++){
                int taken=psum[idx+x-1]-(idx>0?psum[idx-1]:0);
                int temp=taken+solve(idx+x,piles,1,max(limit,x),psum,dp);
                ans=max(ans,temp);
            }
        }else{
            //bobs turn , he will play optimally as well which will result in the minimum value for alice 
            ans=INT_MAX;
            for(int x=1;x<=2*limit&&idx+x<=piles.size();x++){
                int temp=solve(idx+x,piles,0,max(limit,x),psum,dp);
                ans=min(ans,temp);
            }
        }
        return dp[idx][limit][player]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(2,-1)));
        vector<int>psum(n);
        psum[0]=piles[0];
        for(int i=1;i<n;i++){
            psum[i]=psum[i-1]+piles[i];
        }
        int res=solve(0,piles,0,1,psum,dp);
        return res;
    }
};