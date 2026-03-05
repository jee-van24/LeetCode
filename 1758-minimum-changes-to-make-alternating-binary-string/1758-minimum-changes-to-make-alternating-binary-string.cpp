class Solution {
public:
    int minOperations(string s) {
        string temp=s;
        int res1 = 0;
        // ill start string with 1;
        int prev = temp[0];
        for (int i = 1; i < s.size(); i++) {
            if (temp[i] == prev) {
                res1++;
                if (temp[i] == '0') {
                    temp[i] = '1';
                } else {
                    temp[i] = '0';
                }
            }
            prev = temp[i];
        }
        // ill make it the other character and then start
        int res2 = 1;
        temp=s;
        if (temp[0] == '0') {
            temp[0] = '1';
        } else {
            temp[0] = '0';
        }
        prev = temp[0];
        for (int i = 1; i < s.size(); i++) {
            if (temp[i] == prev) {
                res2++;
                if (temp[i] == '0') {
                    temp[i] = '1';
                } else {
                    temp[i] = '0';
                }
            }
            prev = temp[i];
        }
        return min(res1,res2);
    }
};