class Solution {
public:
    int atmost(vector<int>&nums,int targ){
        int l=0;
        int res=0;
        int cnt=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]%2==1){
                cnt++;
            }
            while(cnt>targ){
                if(nums[l]%2==1){
                    cnt--;
                }
                l++;
            }
            res+=r-l+1;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};