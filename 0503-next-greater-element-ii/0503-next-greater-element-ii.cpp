class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            bool flag=false;
            int idx=i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[idx]){
                    res.push_back(nums[j]);
                    flag=true;
                    break;
                }
            }
            if(!flag){
                for(int j=0;j<idx;j++){
                    if(nums[j]>nums[idx]){
                        flag=true;
                        res.push_back(nums[j]);
                        break;
                    }
                }
            }
            if(!flag){
                res.push_back(-1);
            }
        }
        return res;
    }
};