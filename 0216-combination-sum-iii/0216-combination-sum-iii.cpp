class Solution {
public:
    void dfs(int idx,vector<int>&curr,vector<int>&nums,int sum,int k,int target, vector<vector<int>>&res){
        if(idx==nums.size()){
            if(sum==target&&curr.size()==k){
                res.push_back(curr);
            }
            return;
        }
        if(curr.size()==k){
            if(sum==target){
                res.push_back(curr);
            }
            return;
        }
        //the curr is still under k size 
        //so we need to decide with 2 options , include the current idx 
        curr.push_back(nums[idx]);
        dfs(idx+1,curr,nums,sum+nums[idx],k,target,res);
        //after exploring all the possibilities of including the current idx , now dont include 
        curr.pop_back();
        dfs(idx+1,curr,nums,sum,k,target,res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i=0;i<9;i++){
            nums.push_back(i+1);
        };
        vector<int>curr;
        vector<vector<int>>res;
        dfs(0,curr,nums,0,k,n,res);
        return res;
    }
};