class Solution {
public:
    long long minMoves(vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        long long val=0;
        int idx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                val=nums[i];
                idx=i;
                break;
            }
        }
        int n=nums.size();
        if(sum<0)return -1;
        if(idx==-1)return 0;
        int dist=1;
        long long res=0;
        while(val<0){
            int leftidx=(idx-dist+n)%n;
            int rightidx=(idx+dist)%n;
            long long tot=nums[leftidx]+nums[rightidx];
            if(leftidx==rightidx){
                tot-=nums[leftidx];
            }
            long long req=min(abs(val),tot);
            res+=dist*req;
            val+=req;
            dist++;
        }
        return res;
    }
};