class Solution {
public:
    int solve(int idx,vector<int>&cost,vector<int>&dp){
        if(idx==cost.size()+1){
            return 0;
        }
        //im at some valid idx
        //see if the current idx has already been explored
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int curr=cost[idx];
        int minChoice=min(solve(idx+1,cost,dp),solve(idx+2,cost,dp));
        return dp[idx]=curr+minChoice;

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int res=INT_MAX;
        int n=cost.size();
        vector<int>dp(n+1,-1);
        dp[n]=0;
        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};