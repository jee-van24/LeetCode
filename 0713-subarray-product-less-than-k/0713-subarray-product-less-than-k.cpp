class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0;
        int res=0;
        int mul=1;
        for(int r=0;r<nums.size();r++){
            mul*=nums[r];
            if(mul<k){
                res+=(r-l+1);
                continue;
            }
            while(l<=r&&mul>=k){
                mul/=nums[l];
                l++;
            }
            if(l>r){
                mul=1;
            }else if(l<=r){
                res+=(r-l+1);
            }
        }
        return res;
    }
};