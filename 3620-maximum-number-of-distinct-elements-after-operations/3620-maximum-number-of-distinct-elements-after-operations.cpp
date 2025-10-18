class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<int>>seen;
        int res=0;
        int lastused=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int curr=max(lastused+1,num-k);
            if(curr<=num+k){
                res++;
                lastused=curr;
            }
        }
        return res;
            
        return res;
    }
};