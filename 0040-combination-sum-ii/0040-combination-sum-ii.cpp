class Solution {
public:
    set<vector<int>> seen;

    vector<vector<int>> dfs(vector<int> nums, int idx, vector<int> curr, int target) {
        vector<vector<int>> temp;

        if (target == 0) {
            if (seen.find(curr) == seen.end()) {
                temp.push_back(curr);
                seen.insert(curr);
            }
            return temp;
        }

        if (idx >= nums.size() || target < 0) return temp;

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i-1]) continue; // skip duplicates

            vector<int> nextCurr = curr; 
            nextCurr.push_back(nums[i]);
            auto left = dfs(nums, i + 1, nextCurr, target - nums[i]);
            temp.insert(temp.end(), left.begin(), left.end());
        }

        return temp;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); // important for duplicates
        dfs(candidates, 0, curr, target);
        return vector<vector<int>>(seen.begin(), seen.end());
    }
};
