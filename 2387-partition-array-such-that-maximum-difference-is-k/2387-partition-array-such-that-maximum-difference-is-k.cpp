class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int cnt=1;
        sort(nums.begin(),nums.end());
        int curr_num=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-curr_num>k){
                cnt++;
                curr_num=nums[i];
            }
        }
        return cnt;
    }
};