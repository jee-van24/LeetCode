class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false);
        vector<pair<int, int>> temp; // {value, original_index}
        long long score = 0;
        // build the temp array
        for (int i = 0; i < n; i++) {
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());
        for (auto pair : temp) {
            int val = pair.first;
            int idx = pair.second;
            if (marked[idx]) {
                continue;
            }
            score += val;
            marked[idx] = true;
            if (idx > 0) {
                marked[idx - 1] = true;
            }
            if (idx < n - 1) {
                marked[idx + 1] = true;
            }
        }

        return score;
    }
};
