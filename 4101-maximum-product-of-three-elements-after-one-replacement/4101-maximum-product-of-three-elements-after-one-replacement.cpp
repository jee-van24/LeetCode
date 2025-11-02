class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long res=INT_MIN;
        //sort(nums.begin(),nums.end());
        long long maxbest=100000,minbest=-100000;
        int n=nums.size();
        sort(begin(nums), end(nums));
        for(auto n:nums){
            cout<<n<<" ";
        }

        res=abs(1ll*nums[n-1]*nums[n-2]);
        res=max(res,abs(1ll*nums[0]*nums[1]));
        res=max(res,abs(1ll*nums[0]*nums[n-1]));
        res*=1e5;
        cout<<res;
        return res;
        
    }
};