class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int maxe=INT_MIN;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=maxe){
                res++;
                maxe=nums[i];
            }
        }
        return res;
    }
};