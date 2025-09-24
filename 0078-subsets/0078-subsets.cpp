class Solution {
public:
    void backtrack(vector<int>nums,vector<int>curr,int idx,vector<vector<int>>&res){
        if(idx==nums.size()){
            res.push_back(curr);
            return ;
        }
        //else consider both possibilities including the current element and not including the current element 
        curr.push_back(nums[idx]);
        backtrack(nums,curr,idx+1,res);
        curr.pop_back();
        backtrack(nums,curr,idx+1,res);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        backtrack(nums,temp,0,res);
        return res;

    }
};