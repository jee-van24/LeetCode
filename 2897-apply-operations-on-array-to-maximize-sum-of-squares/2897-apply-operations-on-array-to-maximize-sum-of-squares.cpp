class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int>count(32,0);
        for(auto n:nums){
            for(int i=0;i<32;i++){
                if(n&(1<<i)){
                    count[i]++;
                }
            }
        }
        long long res=0;
        const long mod=1e9+7;
        while(k>0){
            long long curr=0;
            for(int i=0;i<32;i++){
                if(count[i]>0){
                    count[i]--;
                    curr=(curr)|(1<<i);
                }
            }
            res=(res+(curr*curr))%mod;
            k--;
        }
        return res;
    }
};