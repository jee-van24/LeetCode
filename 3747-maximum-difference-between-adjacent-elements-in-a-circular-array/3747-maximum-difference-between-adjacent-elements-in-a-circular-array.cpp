class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res=INT_MIN;
        for (int i=1;i<nums.size();i++){
            int diff=0;
            diff=abs(nums[i]-nums[i-1]);
            res=max(res,diff);
        }
       if(abs(nums[0]-nums[nums.size()-1])>res){
        return abs(nums[0]-nums[nums.size()-1]);
       }
        return res;
    }
};