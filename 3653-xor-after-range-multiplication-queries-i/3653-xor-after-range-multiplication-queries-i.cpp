class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int res=0;
        const int mod=1e9+7;
        for(auto &q:queries){
            int l=q[0],r=q[1],k=q[2],val=q[3];
            while(l<=r){
                nums[l]=(1ll*nums[l]*val%mod)%mod;
                l+=k;
            }
        }
        for(auto n:nums){
            res^=n;
        }
        return res;
    }
};