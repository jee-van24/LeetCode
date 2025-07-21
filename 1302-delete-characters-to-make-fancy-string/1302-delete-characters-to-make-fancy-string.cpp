class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        res += s[0];
        int count = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == res.back()) {
                count++;
                if (count < 3) {
                    res += s[i];
                }
            } else {
                count = 1;
                res += s[i];
            }
        }
        return res;
    }
};