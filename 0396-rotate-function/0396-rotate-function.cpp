class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int s=0;
        int left=0;//contribution of the wrapped elements , i,e which go to the last from the front , im doing reverse rotate
        int right=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s+=nums[i];
            right+=i*nums[i];
        }
        int res=right;
        int wrappedsum=0;
        int remainingsum=s;
        for(int i=0;i<n;i++){
            res=max(res,left+right);
            //the current idx is assumed to be wrapped to the end 
            remainingsum-=nums[i];
            right-=remainingsum;
            left-=wrappedsum;
            left+=(n-1)*nums[i];
            wrappedsum+=nums[i];
        }
        return res;
    }
};