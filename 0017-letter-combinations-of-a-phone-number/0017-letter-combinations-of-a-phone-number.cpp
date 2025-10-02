class Solution {
public:
    unordered_map<int, vector<char>> mp;

    void dfs(string &str, int idx, string &curr, vector<string> &res) {
        if (idx >= str.size()) {
            res.push_back(curr);
            return;
        }

        auto &vec = mp[str[idx] - '0']; // access mapping for digit
        for (auto ch : vec) {
            curr.push_back(ch);
            dfs(str, idx + 1, curr, res);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 

        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};

        vector<string> res;
        string curr = "";
        dfs(digits, 0, curr, res);
        return res;
    }
};
