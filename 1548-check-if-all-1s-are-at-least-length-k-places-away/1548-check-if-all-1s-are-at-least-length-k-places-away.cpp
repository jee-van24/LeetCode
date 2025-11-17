class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int previdx=-1;
        if(nums[0]==1){
            previdx=0;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]==1){
                if(previdx==-1){
                    //the first one 
                    previdx=i;
                    continue;
                }else{
                    if(i-(previdx+1)>=k){
                        previdx=i;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};