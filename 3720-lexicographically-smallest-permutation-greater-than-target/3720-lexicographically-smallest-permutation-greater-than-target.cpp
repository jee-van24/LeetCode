class Solution {
public:
    bool solve(string &curr, string &s, string &target,
               string &res, int idx, vector<int>& count,
               bool greater) {

        if (idx == s.size()) {
            if (greater) {
                res = curr;
                return true;
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {

            if (count[ch - 'a'] == 0)
                continue;

            if (!greater && ch < target[idx])
                continue;

            curr.push_back(ch);
            count[ch - 'a']--;

            bool newGreater = greater || ch > target[idx];

            if (solve(curr, s, target, res,
                      idx + 1, count, newGreater)) {
                return true;
            }

            count[ch - 'a']++;
            curr.pop_back();
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {

        string res;
        string curr;

        vector<int> count(26, 0);

        for (char ch : s)
            count[ch - 'a']++;

        solve(curr, s, target, res, 0, count, false);

        return res;
    }
};