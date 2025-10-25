class Solution {
public:
    int totalMoney(int n) {
        vector<int>prefixvals(7,0);
        for(int i=1;i<7;i++){
            prefixvals[i]=i+prefixvals[i-1];
        }
        if(n<=7){
            int sum=0;
            int day=1;
            while(day<=n){
                sum+=day;
                day++;
            }
            return sum;
        }
        int weeks=n/7;//total weeks it can be divided into
        int res=0;//min sum of the first week;
        int i=0;//one week has passed 
        while(i!=weeks){
            res+=28+7*i;
            i++;
            n-=7;
        }
        res+=prefixvals[n];
        res+=n*i;


        cout<<res;
        

        return res;
    }
};