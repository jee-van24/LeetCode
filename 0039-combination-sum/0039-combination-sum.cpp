class Solution {
public:
    void dfs(int idx,vector<int>&nums,vector<int>&curr,int sum,int target, vector<vector<int>>&res){
        if(idx==nums.size()){
            if(sum==target){
                res.push_back(curr);
            }
            return;
        }
        if(sum>target){
            return;//already exceeded the target , no need of further recursive calls 
        }
        //i will always pick the current idx unlimited number of times
        curr.push_back(nums[idx]);
        dfs(idx,nums,curr,sum+nums[idx],target,res);
        curr.pop_back();
        //now dont pick the current idx and move forward 
        dfs(idx+1,nums,curr,sum,target,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>curr;
        dfs(0,candidates,curr,0,target,res);
        return res;

    }
};