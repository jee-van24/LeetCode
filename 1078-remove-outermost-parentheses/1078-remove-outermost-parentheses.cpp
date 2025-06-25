class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int n = s.size();
        int i = 0;

        while (i < n) {
            int balance = 0;
            int j = i;

            while (j < n) {
                if (s[j] == '(') balance++;
                else balance--;
                if (balance == 0) break;
                j++;
            }

            for (int k = i + 1; k < j; k++) {
                res += s[k];
            }

            i = j + 1;
        }

        return res;
    }
};
