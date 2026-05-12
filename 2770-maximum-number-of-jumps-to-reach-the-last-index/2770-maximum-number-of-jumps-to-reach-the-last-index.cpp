class Solution {
public:
    int solve(vector<int>&nums,int idx,int targ,vector<int>&t){
        if(idx==nums.size()-1){
            //reached the last idx , no more steps 
            return 0;
        }
        //if i ever reached the same state through a different branch, i.e same subproblem state , return the answer if already computed
        if(t[idx]!=INT_MIN)return t[idx];
        int res=INT_MIN;
        for(int j=idx+1;j<nums.size();j++){
            if(abs(nums[idx]-nums[j])<=targ){
                int temp=1+solve(nums,j,targ,t);
                res=max(res,temp);
            }
        }
        return t[idx]=res;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int>t(nums.size(),INT_MIN);
        int res=solve(nums,0,target,t);
        if(res>=0)return res;
        return -1;

    }
};