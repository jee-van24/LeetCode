class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        long long res=0;
        int r=grid.size(),c=grid[0].size();
        vector<vector<long long>>dpMax(1ll*r,vector<long long>(1ll*c,0)),dpMin(1ll*r,vector<long long>(1ll*c,0));
        dpMax[0][0]=dpMin[0][0]=grid[0][0];
        for(int i=1;i<c;i++){
            dpMax[0][i]=1ll*dpMax[0][i-1]*grid[0][i];
            dpMin[0][i]=1ll*dpMin[0][i-1]*grid[0][i];
        }
        for(int i=1;i<r;i++){
            dpMax[i][0]=1ll*dpMax[i-1][0]*grid[i][0];
            dpMin[i][0]=1ll*dpMin[i-1][0]*grid[i][0];
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                int curr=grid[i][j];
                long long fromleftmax=dpMax[i][j-1]*curr;
                long long fromleftmin=dpMin[i][j-1]*curr;
                long long fromtopmax=dpMax[i-1][j]*curr;
                long long fromtopmin=dpMin[i-1][j]*curr;
                dpMax[i][j]=max({fromleftmax,fromleftmin,fromtopmax,fromtopmin});
                dpMin[i][j]=min({fromleftmax,fromleftmin,fromtopmax,fromtopmin});
            }
        }
        res=dpMax[r-1][c-1];
        if(res<0)return -1;
        const int mod=1e9+7;
        return res%mod;

    }
};