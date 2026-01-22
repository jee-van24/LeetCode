class Solution {
public:
    int maxSideLength(vector<vector<int>>& grid, int threshold) {
        int len=min(grid.size(),grid[0].size());
        int res=0;
        for(int k=1;k<=len;k++){
            for(int row=0;row+k<=grid.size();row++){
                for(int col=0;col+k<=grid[0].size();col++){
                    int s=0;
                    for(int i=0;i<k;i++){
                        for(int j=0;j<k;j++){
                            s+=grid[row+i][col+j];
                        }
                    }
                    if(s<=threshold){
                        res=max(res,k);
                    }
                }
            }
        }
        return res;
    }
};