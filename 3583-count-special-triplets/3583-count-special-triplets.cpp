class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>left,right;
        long long res=0;
        const int mod=1e9+7;
        for(auto n:nums)right[n]++;
        for(int i=0;i<nums.size();i++){
            right[nums[i]]--;
            int targ=2*nums[i];
            long long leftcnt=left[targ];
            long long rightcnt=right[targ];
            res=(res+(leftcnt*rightcnt)%mod)%mod;
            left[nums[i]]++;
        }
        return res;
    }
};