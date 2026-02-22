class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>map;
        map[0]=1;
        int res=0;
        int currsum=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if(map.count(currsum-goal)){
                res+=map[currsum-goal];
            }
            map[currsum]++;
        }
        return res;
    }
};