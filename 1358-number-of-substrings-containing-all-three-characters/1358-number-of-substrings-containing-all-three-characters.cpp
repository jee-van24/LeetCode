class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> map;
        int l = 0;
        int n = s.size();
        int res = 0;
        for (int r = 0; r < s.size(); r++) {
            map[s[r]]++;

            while (map.size() == 3) {
                res += n - r;
                map[s[l]]--;
                if (map[s[l]] == 0)
                    map.erase(s[l]);
                l++;
            }
        }
        return res;
    }
};