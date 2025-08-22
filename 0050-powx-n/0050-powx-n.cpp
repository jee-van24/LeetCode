class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        if(x==-1&&n%2!=0)return -1;

        long long exp = n;
        if (exp < 0) exp = -exp;

        double res = 1;
        for (long long i = 0; i < exp; i++) {
            res *= x;
        }

        return n >= 0 ? res : 1/res;
    }
};
