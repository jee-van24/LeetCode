class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res=0;
        int left=0;
        unordered_map<int,int>map;
        for(int right=0;right<nums.size();right++){
            map[nums[right]]++;
            while(map[nums[right]]>k){
                map[nums[left]]--;
                if(map[nums[left]]==0){
                    map.erase(nums[left]);
                }
                left++;
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};