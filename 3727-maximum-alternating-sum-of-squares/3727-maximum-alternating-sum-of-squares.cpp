class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long res=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        long long half=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i<n/2){
                half+=nums[i]*nums[i];
            }else{
                res+=nums[i]*nums[i];
            }
        }
        res-=half;
        return res;
    }
};