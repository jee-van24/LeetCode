class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int res=-1;
        dp[0][0][0]=0;
        int cost=0;
        int score=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)continue;//starting cell
                int extracost=(grid[i][j]==0)?0:1;
                int extrascore=grid[i][j];
                for(int oldcost=0;oldcost<=k;oldcost++){
                    int newcost=oldcost+extracost;
                    if(newcost>k)continue;
                    //from top
                    if(i>0&&dp[i-1][j][oldcost]!=-1){
                        dp[i][j][newcost]=max(dp[i][j][newcost],dp[i-1][j][oldcost]+extrascore);
                    }
                    if(j>0&&dp[i][j-1][oldcost]!=-1){
                        dp[i][j][newcost]=max(dp[i][j][newcost],dp[i][j-1][oldcost]+extrascore);
                    }
                }
            }
        }
        for(int c=0;c<=k;c++){
            res=max(res,dp[m-1][n-1][c]);
        }
        return res;
    }
};