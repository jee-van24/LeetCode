class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        vector<int>pmax(nums.size(),0);
        pmax[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pmax[i]=max(nums[i],pmax[i-1]);
        }
        int res=INT_MIN;
        for(int i=k;i<nums.size();i++){
            res=max(res,nums[i]+pmax[i-k]);
        }
        return res;
    }
};