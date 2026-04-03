class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>res(m,0);
        for(int c=0;c<m;c++){
            int end=c;
            bool f=true;
            for(int r=0;r<n;r++){
                if(grid[r][end]==1){
                    if(end+1<m&&grid[r][end+1]==1){
                        end++;
                    }else{
                        res[c]=-1;
                        f=false;
                        break;
                    }
                }else{
                    if(end-1>=0&&grid[r][end-1]==-1){
                        end--;
                    }else{
                        res[c]=-1;
                        f=false;
                        break;
                    }
                }
            }
            if(f)
            res[c]=end;
            else res[c]=-1;
        }
        return res;
    }
};