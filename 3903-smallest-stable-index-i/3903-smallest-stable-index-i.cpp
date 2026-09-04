class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pmax(n,0),pmin(n,0);
        pmax[0]=nums[0];
        pmin[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pmax[i]=max(pmax[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            pmin[i]=min(pmin[i+1],nums[i]);
        }
       
        int minscore=INT_MAX;
        int res=-1;
        for(int i=0;i<n;i++){
            int maxval=pmax[i];
            int minval=pmin[i];
            int score=maxval-minval;
            if(score<=k)return i;
        }
        return -1;

    }
};