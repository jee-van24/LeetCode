class Solution {
public:
    vector<vector<int>>dfs(vector<int>nums,int idx,vector<int>curr,int target){
        vector<vector<int>>temp;
        if(idx>=nums.size()){
            if(target==0){
                temp.push_back(curr);
            }
            return temp;
        }
        if(nums[idx]<=target){
            //will pick it again 
            curr.push_back(nums[idx]);
            auto left=dfs(nums,idx,curr,target-nums[idx]);
            temp.insert(temp.end(),left.begin(),left.end());
            curr.pop_back();
        }
        //now dont include the curr one 
        auto right=dfs(nums,idx+1,curr,target);
        temp.insert(temp.end(),right.begin(),right.end());
        return temp;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>curr;
        res=dfs(candidates,0,curr,target);
        return res;
        
    }
};