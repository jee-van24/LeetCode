class Solution {
public:
    int lowerbound(vector<int>&nums,int& target){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long >res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long long>prefix(n+1,0);
        prefix[0]=0;
        for(int i=0;i<nums.size();i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        for(auto target:queries){
            int idx=lowerbound(nums,target);
            long long opleft=(long long)target*idx-(prefix[idx]);
            long long opright=(prefix.back()-prefix[idx])-((long long)target*(n-idx));
            res.push_back(opleft+opright);

        }
    return res;
    }
};