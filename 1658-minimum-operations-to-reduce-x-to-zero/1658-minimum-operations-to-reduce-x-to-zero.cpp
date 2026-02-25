class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s=0;
        int targ;
        for(auto n:nums){
            s+=n;
        }
        targ=s-x;
        if(targ<0)return -1;
        if(targ==0)return nums.size();
        int l=0;
        int cs=0;
        int n=nums.size(),res=INT_MAX;
        for(int r=0;r<nums.size();r++){
            cs+=nums[r];
            while(cs>targ){
                cs-=nums[l];
                l+=1;
            }
            if(cs==targ){
                res=min(res,n-(r-l+1));
            }
        }
        return res==INT_MAX?-1:res;
    }

};