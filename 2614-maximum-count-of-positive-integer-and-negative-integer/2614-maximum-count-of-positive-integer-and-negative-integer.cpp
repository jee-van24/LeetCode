class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0, neg=0;
        for(auto num:nums){
            if(num==0)continue;
            if(num>0){
                pos++;
            }else{
                neg++;
            }
        }
        return max(pos,neg);
    }
};