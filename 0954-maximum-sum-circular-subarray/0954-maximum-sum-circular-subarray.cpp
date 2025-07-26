class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum=INT_MIN;
        int minsum=INT_MAX;
        int curr_max=0;
        int curr_min=0;
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            curr_max+=nums[i];
            maxsum=max(maxsum,curr_max);
            if(curr_max<0)curr_max=0;
            curr_min+=nums[i];
            minsum=min(curr_min,minsum);
            if(curr_min>0)curr_min=0;
        }
        if(maxsum<0)return maxsum;
        return max(total-minsum,maxsum);
    }
};