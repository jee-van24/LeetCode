class Solution {
public:
    bool solve(int i,vector<int>&nums,vector<int>&t){
        if(i==nums.size()-1)return true;
        if(t[i]!=-1)return t[i];
        for(int j=i+1;j<=i+nums[i];j++){
            if(solve(j,nums,t)){
                return t[j]=true;
            }
        }
      return t[i]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>t(nums.size(),-1);
        bool res=solve(0,nums,t);
        return res;
    }
};