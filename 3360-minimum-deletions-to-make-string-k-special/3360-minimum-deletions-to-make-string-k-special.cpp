class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> map;
        vector<int> vec;
        for (auto c : word) {
            map[c]++;
        }
        for (auto pair : map) {
            vec.push_back(pair.second);
        }
        int min_deletions = INT_MAX;
        for (int i = 0; i < vec.size(); i++) {
            int target = vec[i];
            int curr_deletions = 0;
            for (int j = 0; j < vec.size(); j++) {
                if (vec[j] >= target && vec[j] <= target + k) {
                    continue;
                } else if (vec[j] < target) {
                    curr_deletions += vec[j];
                } else {
                        curr_deletions += vec[j] - (target + k);
                }
            }
                 min_deletions = min(curr_deletions, min_deletions);
            
        }
      return min_deletions;

    }
};