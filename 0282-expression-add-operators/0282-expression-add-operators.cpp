class Solution {
public:
    void dfs(int idx, long long built_val, long long last_val, int target, string& curr,
             string& num, vector<string>& res) {
        if (idx == num.size()) {
            if (built_val == target) {
                res.push_back(curr);
                return;
            }
            return;
        }

        long long val = 0;
        string temp = "";
        for (int i = idx; i < num.size(); i++) {
            if (i > idx && num[idx] == '0') break;
            val = val * 10 + (num[i] - '0');
            temp += num[i];

            if (idx == 0) {
                curr += temp;
                dfs(i + 1, val, val, target, curr, num, res);
                for (int j = 0; j < temp.size(); j++) curr.pop_back();
            } else {
                // '+'
                curr += "+" + temp;
                dfs(i + 1, built_val + val, val, target, curr, num, res);
                for (int j = 0; j < temp.size() + 1; j++) curr.pop_back();

                // '-'
                curr += "-" + temp;
                dfs(i + 1, built_val - val, -val, target, curr, num, res);
                for (int j = 0; j < temp.size() + 1; j++) curr.pop_back();

                // '*'
                curr += "*" + temp;
                dfs(i + 1, built_val - last_val + last_val * val, last_val * val, target, curr, num, res);
                for (int j = 0; j < temp.size() + 1; j++) curr.pop_back();
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string curr = "";
        dfs(0, 0, 0, target, curr, num, res);
        return res;
    }
};
