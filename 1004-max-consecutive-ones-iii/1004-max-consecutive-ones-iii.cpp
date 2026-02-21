class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int left=0;
        int res=0;
        for(int right=0;right<nums.size();right++){
            map[nums[right]]++;
            while(map[0]>k){
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