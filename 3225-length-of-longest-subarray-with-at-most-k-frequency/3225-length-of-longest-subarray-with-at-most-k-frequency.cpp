class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start=0,res=0;
        unordered_map<int,int>map;
        for(int end=0;end<nums.size();end++){
            map[nums[end]]++;
            while(map[nums[end]]>k){
                map[nums[start]]--;
                start++;
            }
            res=max(res,end-start+1);
        }
        return res;
    }
};