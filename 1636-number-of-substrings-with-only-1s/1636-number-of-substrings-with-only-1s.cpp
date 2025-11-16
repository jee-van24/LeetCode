class Solution {
public:
    int numSub(string s) {
        int res=0;
        int cnt=0;
        const int mod=1e9+7;
        for(int right=0;right<s.size();right++){
            if(s[right]=='1'){
                cnt++;
                cnt=cnt%mod;
                res=res%mod;
                res+=cnt;

            }else{
                cnt=0;
            }
        }
        return res;
    }
};