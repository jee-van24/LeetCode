class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res=0,left=0;
        for(int right=2;right<nums.size();right++){
            while(right-left+1>2&&nums[right]!=nums[right-1]+nums[right-2]){
                left++;
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};