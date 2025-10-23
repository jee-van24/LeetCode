class Solution {
public:
    void dfs(int idx,vector<int>&curr,vector<int>&nums,vector<vector<int>>&res){
        res.push_back(curr);
        if(idx==nums.size()){
            return;
        } 
        //i need to make sure no duplicates gets called at the same depth 
        for(int i=idx;i<nums.size();i++){
            if(i>idx&&nums[i]==nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            dfs(i+1,curr,nums,res);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>curr;
        dfs(0,curr,nums,res);
        return res;

    }
};