class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int res=0;
        while(true){
            bool f=true;
            for(int i=1;i<nums.size();i++){
                if(nums[i]<nums[i-1]){
                    f=false;
                    break;
                }
            }
            if(f){
               break;
            }
            int minsum=INT_MAX;
            pair<int,int>idx;
            for(int i=1;i<nums.size();i++){
                int currsum=nums[i]+nums[i-1];
                if(currsum<minsum){
                    idx.first=i-1;
                    idx.second=i;
                    minsum=currsum;
                }
            }
            nums[idx.first]=minsum;
            nums.erase(nums.begin()+idx.second);
            res++;
        }
        return res;
    }
};