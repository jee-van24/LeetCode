class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>res;
        int count=1;
        if(nums.size()==1||k==1)return nums;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1){
                count++;
            }else{
                count=1;
            }
            if(i>=k-1){
                if(count>=k){
                res.push_back(nums[i]);
                }else{
                    res.push_back(-1);
                }
            }
        }
        return res;
    }
};