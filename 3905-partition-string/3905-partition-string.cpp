class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> seen;
        string curr = "";
        vector<string> res;

        for (char ch : s) {
            curr += ch;
            if (seen.find(curr) == seen.end()) {
                seen.insert(curr);
                res.push_back(curr);
                curr = "";
            }
        }

        return res;
    }
};
