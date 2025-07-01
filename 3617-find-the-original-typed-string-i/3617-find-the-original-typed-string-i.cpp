class Solution {
public:
    int possibleStringCount(string word) {
        char curr = word[0];
        int curr_len = 1;
        int n = word.length();
        int res = 0;

        for (int i = 1; i < n; i++) {
            if (word[i] == curr) {
                curr_len++;
            } else {
                res += curr_len - 1;
                curr = word[i];
                curr_len = 1;
            }
        }

        res += curr_len;

        return res;
    }
};
