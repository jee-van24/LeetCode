class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int res=INT_MIN;
        //without rotation
        int sum=0;
        int oldans=0;
        for(int i=0;i<nums.size();i++){
            oldans+=i*nums[i];
            sum+=nums[i];
        }
        res=oldans;
        int n=nums.size();
        for(int k=1;k<nums.size();k++){
            int newans=oldans+sum-n*nums[n-k];
            oldans=newans;
            res=max(res,newans);
        }
        return res;
    }
};