class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int sign = 1;
        int i = 0;

        while (i < s.size() && s[i] == ' ') i++;

        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Overflow check for 32-bit signed int range
            if (res > (LLONG_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
            i++;
        }

        res *= sign;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;

        return static_cast<int>(res);
    }
};
