class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<int>arr;
        const int mod=12345;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                arr.push_back(grid[i][j]);
            }
        }
        vector<int>pref(arr.size(),0),suf(arr.size(),0);
        int n=arr.size();
        pref[0]=arr[0];
        suf[n-1]=arr[n-1];
        int prod=arr[0];
        for(int i=1;i<n;i++){
            pref[i]=prod;
            prod=(1ll*prod*arr[i])%mod;
        }
        prod=suf[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=prod;
            prod=(1ll*prod*arr[i])%mod;
        }
        vector<int>temp(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                temp[i]=suf[i]%mod;
            }else if(i==n-1){
                temp[i]=pref[i]%mod;
            }else{
                temp[i]=(1ll*pref[i]*suf[i])%mod;
            }
        }
        vector<vector<int>>res(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<temp.size();i++){
            int r=i/grid[0].size();
            int c=i%grid[0].size();
            res[r][c]=temp[i];

        }

        return res;
    }
};