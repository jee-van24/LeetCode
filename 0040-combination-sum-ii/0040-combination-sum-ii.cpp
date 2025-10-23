class Solution {
public:
    set<vector<int>>s;
    void dfs(int idx,vector<int>&curr,vector<int>&nums,int target, int sum,vector<vector<int>>&res){
        if(sum>target){
            //no need for further recursive calls cause sum already exceeded target
            return;
        }
        if(sum==target){
            res.push_back(curr);  
            return;
        }
        //i gotta skip duplicate numbers cause shoudnt start a new branch with the same number at the same depth
        for(int i=idx;i<nums.size();i++){
            if(i>idx&&nums[i]==nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            dfs(i+1,curr,nums,target,sum+nums[i],res);
            curr.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>curr;
        dfs(0,curr,candidates,target,0,res);
        return res;
    }
};
