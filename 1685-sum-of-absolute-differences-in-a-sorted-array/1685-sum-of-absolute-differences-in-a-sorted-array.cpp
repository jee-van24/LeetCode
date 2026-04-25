class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>psum(nums.size(),0);
        psum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            psum[i]=psum[i-1]+nums[i];
        }
        vector<int>res(nums.size(),0);
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i==0){
                //contribution from the right only
                int times=n-i-1;
                int sum=psum[n-1]-psum[0];
                int val=sum-nums[i]*times;
                res[i]=val;
            }else if(i==n-1){
                //contribution only from left
                int times=i;
                int sum=psum[n-2];
                int val=nums[i]*times-sum;
                res[i]=val;
            }else{
                //both contribution from left and right
                int ltimes=i;
                int rtimes=n-i-1;
                int lsum=psum[i-1];
                int rsum=psum[n-1]-psum[i];
                res[i]+=ltimes*nums[i]-lsum;
                res[i]+=rsum-nums[i]*rtimes;
            }
        }
        return res;
    }
};