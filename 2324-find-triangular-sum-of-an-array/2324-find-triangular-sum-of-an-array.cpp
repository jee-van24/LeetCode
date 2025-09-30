class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        while(nums.size()!=1){
            vector<int>temp;
            for(int i=1;i<nums.size();i++){
                int curr=(nums[i]+nums[i-1])%10;
                temp.push_back(curr);
            }
            nums=temp;
        }
        return nums[0];
    }
};