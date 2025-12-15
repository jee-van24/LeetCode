class Solution {
public:
    int numberOfWays(string s) {
        int cnt = 0;
        for (auto ch : s) {
            if (ch == 'S') {
                cnt++;
            }
        }
        const int mod=1e9+7;
        long long res=1;
        if(cnt<1||cnt%2==1)return 0;
        if(cnt==2)return 1;
        int temp=0;
        for(int i=0;i<s.size();i++){
            if(cnt==2){
                return res%mod;//you have come to the last 
            }
            if(s[i]=='S'){
                temp++;
            }
            if(temp==2){
                int j=i+1;
                int x=0;
                while(s[j]!='S'){
                    x++;
                    j++;
                }
                x=x+1;
                cnt-=2;
                i=j-1;
                temp=0;
                res=(res%mod)*x;
            }
        }
        return res;
    }
};