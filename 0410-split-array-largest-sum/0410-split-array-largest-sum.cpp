class Solution {
public:
    bool largest_sum(vector<int>&arr,int sum,int max_allowed_subarray){
        int curr_sum=0;
        int subarray_count=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]+curr_sum<=sum){
                curr_sum+=arr[i];
            }else{
                subarray_count++;
                curr_sum=arr[i];
            }
            if(subarray_count>max_allowed_subarray){
                return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(largest_sum(nums,mid,k)==true){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};