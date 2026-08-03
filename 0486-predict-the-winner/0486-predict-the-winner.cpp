class Solution {
public:
     int solve(int l,int r , vector<int>&nums,int player, vector<vector<vector<int>>>&dp){
        if(l==r){

            //theres only one idx left , the current player has to take this val
            if(player==0)
            return nums[l];
            return 0;
        }
        if(dp[l][r][player]!=-1){
            return dp[l][r][player];
        }
        //i can either take from the left or the right and add it to my current players score
        int res=0;
        int p=-1;
        if(player==0){
             res=INT_MIN;
             p=1;
             res=max(res,nums[l]+solve(l+1,r,nums,p,dp));
             res=max(res,nums[r]+solve(l,r-1,nums,p,dp));
        }else{
            res=INT_MAX;
            p=0;
            res=min(res,solve(l+1,r,nums,p,dp));
            res=min(res,solve(l,r-1,nums,p,dp));
        }
        return dp[l][r][player]=res;
    }
    bool predictTheWinner(vector<int>& nums) {
        //i have to consider the entire range of the nums size 
        //so l can vary from 0 to n , r can very from 0 to n 
        //player is either 1 or 2 
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int res=solve(0,n-1,nums,0,dp);
        int total=accumulate(nums.begin(),nums.end(),0);
        if(res>=total-res)return true;
        return false;
    }
};