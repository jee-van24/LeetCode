class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>p(n,0),rsum(n,0),lsum(n,0);
        p[0]=nums[0];
        for(int i=1;i<n;i++){
            p[i]=p[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            lsum[i]=i==0?0:p[i-1];
            rsum[i]=i==n-1?0:p[n-1]-p[i];
        }
        vector<int>res(n,0);
        for(int i=0;i<nums.size();i++){
            res[i]=abs(lsum[i]-rsum[i]);
        }
        return res;

    }
};