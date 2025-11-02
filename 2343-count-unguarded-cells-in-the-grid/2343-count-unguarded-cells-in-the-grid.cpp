class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(auto g:guards){
            grid[g[0]][g[1]]=1;
        }
        for(auto w:walls){
            grid[w[0]][w[1]]=2;
        }
        for(auto vec:guards){
            int r=vec[0];
            int c=vec[1];
            //go up , go down, go left , go right 
            for(int i=r-1;i>=0;i--){
                if(grid[i][c]==2||grid[i][c]==1)break;
                grid[i][c]=3;
            }
            for(int i=r+1;i<m;i++){
                if(grid[i][c]==2||grid[i][c]==1){
                    break;
                }
                grid[i][c]=3;
            }
            for(int i=c+1;i<n;i++){
                if(grid[r][i]==2||grid[r][i]==1)break;
                grid[r][i]=3;
            }
            for(int i=c-1;i>=0;i--){
                if(grid[r][i]==2||grid[r][i]==1)break;
                grid[r][i]=3;
            }

        }
        int res=0;
        for(auto row:grid){
            for(auto num:row){
                if(num==0){
                    res++;
                }
            }
        }
        return res;

    }
};