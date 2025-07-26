class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_map<int,int>map;
       for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            if(map.find(curr)!=map.end()){
                if(abs(map[curr]-i)<=k){
                   return true;
                }else{
                    map[curr]=i;
                }
            }else{
                map[curr]=i;
            }
       }
       return false;
    }
};