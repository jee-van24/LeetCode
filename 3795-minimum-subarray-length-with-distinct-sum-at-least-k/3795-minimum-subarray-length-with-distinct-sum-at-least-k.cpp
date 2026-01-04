class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int res=INT_MAX;
        unordered_map<int,int>map;
        int left=0;
        int sum=0;
        for(int right=0;right<nums.size();right++){
            if(map[nums[right]]==0){
                sum+=nums[right];
            }
            map[nums[right]]++;
            while(sum>=k){
                res=min(res,right-left+1);
                map[nums[left]]--;
                if(map[nums[left]]==0){
                    sum-=nums[left];
                    map.erase(nums[left]);
                }
                left++;
            }
        }
        return res==INT_MAX?-1:res;
    }
};