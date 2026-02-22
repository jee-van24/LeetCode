class Solution {
public:
    int atmost(vector<int>&nums,int targ){
        unordered_map<int,int>map;
        int l=0,res=0;
        for(int r=0;r<nums.size();r++){
            map[nums[r]]++;
            while(map.size()>targ){
                map[nums[l]]--;
                if(map[nums[l]]==0){
                    map.erase(nums[l]);
                }
                l++;
            }
            res+=r-l+1;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};