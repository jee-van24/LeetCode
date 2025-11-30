class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int targ=nums[i];
            int left=0,right=nums.size()-1;
            int idx=nums.size();//no greater element lets assume
            while(left<=right){
                int mid=left+(right-left)/2;
                if(nums[mid]>targ){
                    idx=mid;
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
            if(nums.size()-idx>=k){
                cnt++;
            }
        }
        return cnt;
    }
};