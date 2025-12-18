class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long>pricepref(n,0ll);
        vector<long long>stratpref(n,0ll);
        pricepref[0]=prices[0];
        stratpref[0]=prices[0]*strategy[0];
        for(int i=1;i<n;i++){
            pricepref[i]=prices[i]+pricepref[i-1];
            stratpref[i]=prices[i]*strategy[i]+stratpref[i-1];
        }
        long long res=stratpref[n-1];//no changes made
        long long comp=res; 
        long long maxgain=INT_MIN;
        int left=0;
        for(int right=0;right<n;right++){
            while(right-left+1>k){
                left++;
            }
            if(right-left+1==k){
                //this the curr subarray 
                //calc the currgain you can make in this subarray 
                int startright=left+k/2;
                long long ogcont=(left==0)?stratpref[right]:stratpref[right]-stratpref[left-1];
                long long currgain=pricepref[right]-(startright==0?0:pricepref[startright-1])-ogcont;
                 res=max(res,comp+currgain);
               
            }
        }
        return res;
    }
};