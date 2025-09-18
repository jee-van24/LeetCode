class Solution {
public:
    long long ans(long long base, long long exp, const long long MOD) {
        long long res = 1;
        while (exp != 0) {
            if (exp % 2 != 0) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long evenidxcnt, oddidxcnt;
        if (n % 2 == 0) {
            evenidxcnt = oddidxcnt = n / 2;
        } else {
            evenidxcnt = (n + 1) / 2;
            oddidxcnt = n / 2;
        }

        const long long MOD = 1e9 + 7;
        long long even = ans(5, evenidxcnt, MOD);
        long long odd = ans(4, oddidxcnt, MOD);
        long long res = (odd * even) % MOD;

        return (int)res; 
    }
};
