class Solution {
public:
    vector<long long> maximumEvenSplit(long long n) {
        if((n&1)==1){
            return {};
        }
        long long num=n;
        vector<long long>res;
        long long i=2;
        long long sum=0;
        while(i<=num){
            long long temp=min(i,num);
            res.push_back(temp);
            num-=temp;
            sum+=i;
            i+=2;
        }
        if(sum==n){
            return res;
        }else{
            res.back()+=(n-sum);
        }
        return res;
    }
};