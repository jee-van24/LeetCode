class Solution {
public:
    vector<vector<int>> backtrack(vector<int>& nums, vector<int> curr, int idx) {
        if (idx == nums.size()) {
            return {curr};
        }

        // include nums[idx]
        curr.push_back(nums[idx]);
        auto left = backtrack(nums, curr, idx + 1);

        // exclude nums[idx]
        curr.pop_back();
        auto right = backtrack(nums, curr, idx + 1);

        // merge both results
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // generate all subsets
        vector<vector<int>> res = backtrack(nums, {}, 0);

      
        set<vector<int>> s(res.begin(), res.end());

       
        return vector<vector<int>>(s.begin(), s.end());
    }
};
