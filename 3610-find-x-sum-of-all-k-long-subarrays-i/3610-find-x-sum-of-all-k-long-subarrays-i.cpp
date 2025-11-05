class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        for (int i = 0; i + k <= nums.size(); i++) {
            unordered_map<int, int> map;
            int sum = 0;
            for (int j = i; j < i + k; j++) {
                map[nums[j]]++;
                sum += nums[j];
            }
            auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.second == b.second)
                    return a.first > b.first;
                return a.second > b.second;
            };
            if (map.size() < x) {
                res.push_back(sum);
            } else {
                int s = 0;
                // get the x most top elements
                vector<pair<int, int>> vec(map.begin(), map.end());
                sort(vec.begin(), vec.end(), cmp);

                for (int j = 0; j < x; j++) {
                    s += vec[j].first * vec[j].second;
                    cout << vec[j].first << " " << vec[j].second << endl;
                }
                res.push_back(s);
            }
        }
        return res;
    }
};