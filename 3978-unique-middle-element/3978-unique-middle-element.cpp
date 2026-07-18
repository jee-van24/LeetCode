class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>map;
        for(auto n:nums){
            map[n]++;
        }
        int el=nums[nums.size()/2];
        if(map[el]>1)return false;
        return true;
    }
};