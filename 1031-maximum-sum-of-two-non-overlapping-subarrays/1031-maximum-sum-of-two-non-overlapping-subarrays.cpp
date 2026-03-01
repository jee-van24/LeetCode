class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstlen, int secondlen) {
        int res;
        int n=nums.size();
        for(int i=0;i<=n-firstlen;i++){
            int maxsum1=0;
            for(int j=i;j<i+firstlen;j++){
                maxsum1+=nums[j];
            }
            for(int j=0;j<=n-secondlen;j++){
                
                if(i+firstlen<=j||j+secondlen<=i){
                    int maxsum2=0;
                    for(int k=j;k<j+secondlen;k++){
                        maxsum2+=nums[k];
                    }
                    res=max(res,maxsum1+maxsum2);
                }
            }
        }
        return res;
    }
};