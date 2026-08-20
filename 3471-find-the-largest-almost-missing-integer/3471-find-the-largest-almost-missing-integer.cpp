class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int res=-1;
        int l=0;
        unordered_map<int,int>map,window;
        for(int r=0;r<nums.size();r++){
            map[nums[r]]++;
            if(r-l+1==k){
                for(auto p:map){
                    window[p.first]++;
                }
                map[nums[l]]--;
                if(map[nums[l]]==0){
                    map.erase(nums[l]);
                }
                l++;
            }
        }
        for(auto p:window){
            if(p.second==1){
                res=max(res,p.first);
            }
        }
        return res;
    }
};