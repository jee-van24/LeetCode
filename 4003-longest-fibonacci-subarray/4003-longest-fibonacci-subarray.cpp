class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       
       int res=2;
       int currlen=0;
       for(int right=2;right<nums.size();right++){
            if(nums[right-2]+nums[right-1]==nums[right]){
                if(currlen==0){
                    currlen=3;
                }else{
                    currlen++;
                }
            }else{
                currlen=0;
            }
            res=max(res,currlen);
       } 
       return res;
    }
};