class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count=0;
        int left=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0){
                count+=right-left+1;
            }else{
                left=right+1;
            }
        }
        return count;
    }
};