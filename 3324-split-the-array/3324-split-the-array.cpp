class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int>map;
        for(auto num:nums){
            map[num]++;
            if(map[num]>2){
                return false;
            }
        }
        return true;
    }
};