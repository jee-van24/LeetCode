class Solution {
public:
    int findMin(vector<int>& nums) {
        int res=INT_MAX;
        int l=0,r=nums.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            int curr=nums[m];
            //check which part is sorted 
            if(nums[l]<=curr&&curr>nums[r]){
                res=min(res,curr);
                l=m+1;
            }else{
                res=min(res,curr);
                r=m-1;
            }
        }
        return res;
    }
};