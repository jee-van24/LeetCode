class Solution {
public:
    void powerset(int idx,vector<int>curr,vector<int>&nums,vector<vector<int>>&res){
        if(idx==nums.size()){
            res.push_back(curr);
            return;
        }
        //can pick the current idx and not pick the current idx
        curr.push_back(nums[idx]);
        powerset(idx+1,curr,nums,res);
        //undo the change and explore the other possibility
        curr.pop_back();
        powerset(idx+1,curr,nums,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>arr;

        powerset(0,arr,nums,res);
        return res;
    }
};