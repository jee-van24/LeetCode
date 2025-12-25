class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res=0;
        sort(happiness.rbegin(),happiness.rend());
        int i=0;
        int j=0;
        while(i<k&&happiness[i]>=0){
            if(i==0){
                res+=happiness[i];
                i++;
                j++;
                continue;
            }
            if(happiness[i]>=0){
                if(happiness[i]-j>0){
                    res+=happiness[i]-j;
                    i++;
                    j++;
                    continue;
                }else if(happiness[i]-j==0){
                    break;
                }
            }
        }
        return res;
    }
};