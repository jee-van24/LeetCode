class Solution {
public:
    unordered_map<int, vector<char>> mp;

    vector<string> dfs(string str, int idx, string curr) {
        vector<string>res;
        if (idx >= str.size()) {
            return {curr};
        }

        auto &vec = mp[str[idx] - '0']; // access mapping for digit
        for (auto ch : vec) {
            curr.push_back(ch);
            auto vec=dfs(str, idx + 1, curr);
            res.insert(res.end(),vec.begin(),vec.end());
            curr.pop_back();
        }
        return res;
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
        res=dfs(digits, 0, curr);
        return res;
    }
};
