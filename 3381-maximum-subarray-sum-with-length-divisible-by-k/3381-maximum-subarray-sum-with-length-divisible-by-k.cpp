class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        long long res=LLONG_MIN;
        for(int i=0;i<k;i++){
            long long currsum=0;
            for(int j=i;j+k-1<nums.size();j+=k){
                long long ksum=prefix[j+k-1]-(j==0?0:prefix[j-1]);
                currsum+=ksum;
                res=max(res,currsum);
                currsum=max(currsum,0ll);
            }
        }
        return res;
    }
};