class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int res=INT_MAX;
        sort(nums.begin(),nums.end());
        //remove 2 smallest numbers;
        int low=nums[2];
        int high=nums[nums.size()-1];
         res=min(res,high-low);
        //remove 2 largest numbers
        low=nums[0];
        high=nums[nums.size()-3];
        res=min(res,high-low);
        //remove 1 smallest and 1 largest
        low=nums[1];
        high=nums[nums.size()-2];
        res=min(res,high-low);
        return res;
    }
};