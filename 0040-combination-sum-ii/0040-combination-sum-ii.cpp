class Solution {
public:
    vector<vector<int>> dfs(vector<int> nums, int idx, vector<int> curr, int target) {
        vector<vector<int>> temp;

        if (target == 0) {
            temp.push_back(curr);
            return temp;  
        }

        if (idx >= nums.size() || target < 0)
            return temp;

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue; 

            curr.push_back(nums[i]);    
            auto left = dfs(nums, i + 1, curr, target - nums[i]);
            curr.pop_back();
            temp.insert(temp.end(), left.begin(), left.end());
        }

        return temp;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res=dfs(candidates, 0, {}, target);
        return res;
    }
};
