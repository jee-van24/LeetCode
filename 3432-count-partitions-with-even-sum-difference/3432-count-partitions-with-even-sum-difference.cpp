class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int res = 0;
        int currsum = 0;
        int totsum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size()-1; i++) {
            currsum += nums[i];
            int remsum = totsum - currsum;
            if ((remsum - currsum) % 2 == 0) {
                res++;
            }
        }
        if(res==0)return res;
        return res;
    }
};