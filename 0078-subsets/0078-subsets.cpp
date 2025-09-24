class Solution {
public:
    vector<vector<int>> backtrack(vector<int>nums,vector<int>curr,int idx){
        if(idx==nums.size()){
            return {curr};
        }
        //else consider both possibilities including the current element and not including the current element 
        curr.push_back(nums[idx]);
        auto left=backtrack(nums,curr,idx+1);
        curr.pop_back();
        auto right=backtrack(nums,curr,idx+1);
        left.insert(left.end(),right.begin(),right.end());
        return left;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        res=backtrack(nums,temp,0);
        return res;

    }
};