class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        bool f=true;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1]-prices[i]!=1){
                    f=false;
                  break;
            }
        }
        long long n=prices.size();
        if(f)return n*(n+1)/2;
        long long res=1;
        int cnt=1;
        const long mod=1e9+7;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1]-prices[i]==1){
                cnt++;
                res=res+cnt%mod;
            }else{
                cnt=1;
                res+=cnt%mod;
            }
        }
        return res;
    }
};