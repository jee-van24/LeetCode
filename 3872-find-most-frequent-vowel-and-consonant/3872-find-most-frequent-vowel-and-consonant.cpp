class Solution {
public:
    int maxFreqSum(string s) {
        int maxv = 0;
        int maxc = 0;
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> map;
        for (auto ch : s) {
            map[ch]++;
            if (set.find(ch) != set.end()) {
                maxv = max(maxv, map[ch]);
            } else {
                maxc = max(maxc, map[ch]);
            }
        }

        return maxv + maxc;
    }
};