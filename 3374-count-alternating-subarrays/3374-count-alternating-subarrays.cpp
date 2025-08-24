class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long res=1;
        long long count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                count++;
                res+=count;
            }else{
                count=1;
                res+=count;
            }
        }
        return res;
    }
};