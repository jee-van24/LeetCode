class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res=0;
        sort(happiness.rbegin(),happiness.rend());
        int i=0;
        int j=0;
        while(i<k&&happiness[i]-j>=0){
            if(happiness[i]-j>0){
                res+=happiness[i]-j;
                i++;
                j++;
                continue;
                }else{
                    break;
                }
        }
        return res;
    }
};