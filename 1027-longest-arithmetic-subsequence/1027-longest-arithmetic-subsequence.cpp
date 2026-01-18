class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int res=0;
        for(int i=0;i<nums.size()-2;i++){
            int curr=nums[i];
            for(int j=i+1;j<nums.size()-1;j++){
                int len=2;
                int diff=nums[j]-curr;
                int last=nums[j];
                for(int k=j+1;k<nums.size();k++){
                    if(nums[k]-last==diff){
                        len++;
                        last=nums[k];
                    }
                }
                res=max(res,len);
            }
        }
        return res;
    }
};