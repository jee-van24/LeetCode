class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> paired;
        for (int i = 0; i < nums.size(); i++) {
            paired.push_back({nums[i], i});
        }

        sort(paired.begin(), paired.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first; 
        });

        vector<int> idx;
        for (int i = 0; i < k; i++) {
            idx.push_back(paired[i].second);
        }

        sort(idx.begin(), idx.end());

        vector<int> res;
        for (int i = 0; i < idx.size(); i++) {
            res.push_back(nums[idx[i]]);
        }

        return res;
    }
};
