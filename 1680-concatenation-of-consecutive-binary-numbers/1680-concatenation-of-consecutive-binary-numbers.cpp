class Solution {
public:
    int noofbits(int n){
        int ans=0;
        while(n!=0){
            ans++;
            n/=2;
        }
        return ans;
    }
    int concatenatedBinary(int n) {
       long long res=1;
       const int mod=1e9+7;
       for(int i=2;i<=n;i++){
            int bits=noofbits(i);
            res=((res<<bits)+i)%mod;
       }
       return res;
    }
};