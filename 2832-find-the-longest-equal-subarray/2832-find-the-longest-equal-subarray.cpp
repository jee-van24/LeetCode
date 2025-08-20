class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int res=0;
        unordered_map<int,int>map;
        int left=0;
        int maxfreq=0;
        for(int right=0;right<nums.size();right++){
            map[nums[right]]++;
            maxfreq=max(maxfreq,map[nums[right]]);
            while(right-left+1-maxfreq>k){
                map[nums[left]]--;
                left++;
            }
            res=max(res,maxfreq);
        }
        return res;
    }
};