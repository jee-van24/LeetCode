class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res=0;
        for(int i=0;i<nums.size()-1;i++){
            int maxe=nums[i];
            int mine=nums[i];
            for(int j=i+1;j<nums.size();j++){
                maxe=max(nums[j],maxe);
                mine=min(nums[j],mine);
                res+=maxe-mine;
            }
        }
        return res;
    }
};