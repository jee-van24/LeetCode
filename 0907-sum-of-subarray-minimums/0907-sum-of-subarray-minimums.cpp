class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<vector<int>>s;
        int n=arr.size();
        vector<int>prev(n,0),next(n,0);
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&s.top()[1]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                next[i]=n;

            }else{
                next[i]=s.top()[0];
            }
            s.push({i,arr[i]});
        }
        while(!s.empty())s.pop();
        for(int i=0;i<n;i++){
            while(!s.empty()&&s.top()[1]>arr[i]){
                s.pop();
            }
            if(s.empty()){
                prev[i]=-1;

            }else{
                prev[i]=s.top()[0];
            }
            s.push({i,arr[i]});
        }
        
        long long res=0;
        const int mod =1e9+7;
        for(int i=0;i<n;i++){
            long long l=1ll*prev[i];
            long long r=1ll*next[i];
            long long leftcnt=i-l;
            long long rightcnt=r-i;
            res=(res+arr[i]*leftcnt%mod*rightcnt%mod)%mod;
        }
        return (int)res;
    }
};