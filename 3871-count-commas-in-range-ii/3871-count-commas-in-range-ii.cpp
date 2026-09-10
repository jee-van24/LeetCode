class Solution {
public:
    long long countCommas(long long n) {
        long long res=0;
        long long lower=1e3;
        long long  commas=1;
        while(lower<=n){
            long long upper=lower*1e3-1;
            if(upper>n){
                upper=n;
            }
            long long nos=upper-lower+1;
            res+=nos*commas;
            commas++;
            lower*=1e3;
        }
        return res;
    }
};