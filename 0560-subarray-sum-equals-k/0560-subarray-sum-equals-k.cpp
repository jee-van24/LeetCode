class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int currsum=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if(currsum==k){
                res++;
            }
            int targ=currsum-k;
            if(map.find(targ)!=map.end()){
                res+=map[targ];
            }
            map[currsum]++;
        }
        return res;
    }
};