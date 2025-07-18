class Solution {
public:
    bool canBeValid(string s, string locked) {
        int min_open_mismatch = 0, max_open_mismatch = 0;
        if (s.size() % 2 != 0) return false;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    min_open_mismatch++;
                    max_open_mismatch++;
                } else {
                    min_open_mismatch--;
                    max_open_mismatch--;
                }
            } else {
                min_open_mismatch--;
                max_open_mismatch++;
            }
            min_open_mismatch = max(min_open_mismatch, 0);
            if (max_open_mismatch < 0) return false;
        }
        return min_open_mismatch == 0;
    }
};
