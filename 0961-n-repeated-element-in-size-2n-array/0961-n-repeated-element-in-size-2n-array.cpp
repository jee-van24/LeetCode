class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int f=nums.size()/2;
        unordered_map<int,int>map;
        for(auto n:nums){
            map[n]++;
        }
        for(auto p:map){
            if(p.second==f)return p.first;
        }
        return 0;
    }
};