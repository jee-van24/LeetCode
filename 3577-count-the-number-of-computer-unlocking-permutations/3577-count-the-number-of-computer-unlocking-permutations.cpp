class Solution {
public:
    long long fact(int n,const int mod){
        if(n==1){
            return 1;
        }
        return n*(fact(n-1,mod)%mod);
    }
    int countPermutations(vector<int>& complexity) {
            int n=complexity.size();
            const int mod=1e9+7;
            int minele=*min_element(complexity.begin(),complexity.end());
            int mincnt=count(complexity.begin(),complexity.end(),minele);
            if(complexity[0]==minele&&mincnt>1)return 0;
            if(complexity[0]==minele&&mincnt==1)return fact(n-1,mod)%mod;
            return 0;

    }
};