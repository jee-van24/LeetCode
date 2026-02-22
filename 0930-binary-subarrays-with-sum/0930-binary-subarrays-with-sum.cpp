class Solution {
public:
    int atmost(vector<int>&nums,int tar){
        if(tar<0)return 0;
        int res=0;
        int l=0;
        int s=0;
        for(int r=0;r<nums.size();r++){
            s+=nums[r];
            while(s>tar){
                s-=nums[l];
                l++;
            }
            res+=r-l+1;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};