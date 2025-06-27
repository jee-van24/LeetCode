class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        unordered_set<char> used;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (map.find(ch) == map.end()) {
                if (used.find(t[i]) == used.end()) {
                    map[ch] = t[i];
                    used.insert(t[i]);
                } else {
                    return false;
                }
            }

            if (map[ch] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
