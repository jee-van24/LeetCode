class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int res=0;
        for(int j=0;j<nums.size();j++){
            while(i<nums.size()&&1ll*nums[i]*k<1ll*nums[j]){
                i++;
            }
            res=max(res,j-i+1);
        }
        return nums.size()-res;
    }
};