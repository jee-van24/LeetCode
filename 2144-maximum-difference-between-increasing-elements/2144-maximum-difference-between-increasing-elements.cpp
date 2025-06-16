class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max_diff=-1;
        int curr_min=nums[0];
        for(int i=1;i<nums.size();i++){
            int curr_max=nums[i];
            if(curr_max>curr_min){
                max_diff=max(max_diff,curr_max-curr_min);
            }
            curr_min=min(curr_min,nums[i]);
        }
        return max_diff;
    }
};