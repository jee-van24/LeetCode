class Solution {
public:
    const long long MOD = 1e9 + 7;

    
    long long modPow(long long base, long long exp) {
        if (exp == 0) return 1;

        long long half = modPow(base, exp / 2);
        long long res = (1LL * half * half) % MOD;  

        if (exp % 2 != 0) {
            res = (res * base) % MOD; 
        }

        return res;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  
        long long oddCount = n / 2;         

        long long even = modPow(5, evenCount); 
        long long odd = modPow(4, oddCount);    

      
        long long res = (1LL * even * odd) % MOD;

        return (int)res;
    }
};
