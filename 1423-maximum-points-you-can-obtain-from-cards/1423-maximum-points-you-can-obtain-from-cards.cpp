class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int lsum=0,rsum=0,res=0;
        for(int i=0;i<k;i++){
            lsum+=arr[i];
        }
        res=lsum;
        int end=arr.size()-1;
        for(int i=k-1;i>=0;i--){
            lsum-=arr[i];
            rsum+=arr[end];
            end--;
            res=max(res,lsum+rsum);
        }
        return res;
    }
};