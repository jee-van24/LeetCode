class Solution {
public:
    int upperbound(vector<int>&nums){
        int low=0,high=nums.size()-1;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>0){//go left
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
        //return ans;
    }
    int lowerbound(vector<int>&nums){
        int low=0,high=nums.size()-1;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=0){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
       // return ans;
    }

    int maximumCount(vector<int>& nums) {
        int upper=upperbound(nums);
        int pos=nums.size()-upper;
        int neg=lowerbound(nums);
        return max(pos,neg);
    }
};