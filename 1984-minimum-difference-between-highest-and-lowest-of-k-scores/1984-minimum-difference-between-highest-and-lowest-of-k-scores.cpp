class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        int res=INT_MAX;
        for(auto n:nums){
            cout<<n<<" ";
        }
        cout<<endl;
        for(int i=0;i+k<=nums.size();i++){
            int maxe=nums[i];
            int mine=nums[i];
            for(int j=i;j<i+k;j++){
                maxe=max(maxe,nums[j]);
                mine=min(mine,nums[j]);
            }
            res=min(res,maxe-mine);
            cout<<res<< " ";
        }
        return res;
    }
};