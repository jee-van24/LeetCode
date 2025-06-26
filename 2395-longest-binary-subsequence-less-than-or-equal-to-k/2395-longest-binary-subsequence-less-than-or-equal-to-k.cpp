class Solution {
public:
    int longestSubsequence(string s, int k) {
        int right = s.size() - 1;
        long long deci_val = 0, size = 0, power = 1;
        while (right >= 0) {
            char ch = s[right];
            int dig = ch - '0';
            if (dig == 0) {
                size++;
                if (power <= k){
                    power *= 2;
                }
                right--;
                continue;
            }else {
                if (deci_val + power <= k) {
                    deci_val += power;
                    size++;
                }
                if (power <= k){
                    power *= 2;
                }
            }
            right--;
        }
        return size;
    }
};
