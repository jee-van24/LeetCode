class Solution {
public:
    string comp(string &a, string &b) {
        if (a.empty()) return b;

        if (a.size() != b.size())
            return a.size() < b.size() ? a : b;

        return a < b ? a : b;
    }

    string shortestBeautifulSubstring(string s, int k) {
        string res;
        int l = 0;

        unordered_map<char, int> mp;

        for (int r = 0; r < s.size(); r++) {

            mp[s[r]]++;

            while (mp['1'] == k) {

                // Remove leading zeros from the current window.
                while (s[l] == '0') {
                    mp[s[l]]--;
                    if (mp[s[l]] == 0)
                        mp.erase(s[l]);

                    l++;
                }

                string temp = s.substr(l, r - l + 1);
                res = comp(res, temp);

                // Remove the leftmost 1.
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);

                l++;
            }
        }

        return res;
    }
};