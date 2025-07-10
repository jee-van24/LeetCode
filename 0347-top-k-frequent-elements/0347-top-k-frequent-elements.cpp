class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        vector<pair<int, int>> check;
        vector<int> res;
        for (int num : nums) {
            freqMap[num]++;
        }
        for (auto& it : freqMap) {
            check.push_back({it.second, it.first});
        }
        sort(check.begin(), check.end());
        for (int i = check.size() - 1; i >= 0; i--) {
            if (res.size() == k) break;
            res.push_back(check[i].second);
        }

        return res;
    }
};
