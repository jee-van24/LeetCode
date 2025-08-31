class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int bestmax=INT_MIN;
        int bestmin=INT_MAX;
        int maxsum=0,minsum=0;
        for(auto num:nums){
            maxsum+=num;
            minsum+=num;
            if(maxsum<0){
                maxsum=0;
            }
            bestmax=max(maxsum,bestmax);
            if(minsum>0){
                minsum=0;
            }
            bestmin=min(bestmin,minsum);
        }
        return max(abs(bestmin),abs(bestmax));
          
    }
};