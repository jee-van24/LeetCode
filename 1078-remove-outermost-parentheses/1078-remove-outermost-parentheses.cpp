class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int i = 0;

        while (i < s.size()) {
            int balance = 0;
            int j = i;

            while (j < s.size()) {
                if (s[j] == '(') balance++;
                else balance--;
                if (balance == 0) break;
                j++;
            }

            res += s.substr(i + 1, j - i - 1);
            i = j + 1;
        }

        return res;
    }
};