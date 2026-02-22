class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long l=0,s=0,res=0;
        for(int r=0;r<nums.size();r++){
            s+=nums[r];
            while(s*(r-l+1)>=k){
                s-=nums[l];
                l++;
            }
            res+=r-l+1;
        }
        return res;
    }
};