class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minrow = -1, mincol = -1;
        int maxrow = -1, maxcol = -1;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    if (minrow == -1) {
                        minrow = i;
                        maxrow = i;
                        maxcol=j;
                        mincol=j;
                    }else{
                        maxrow=i;
                        mincol=min(mincol,j);
                        maxcol=max(maxcol,j);
                    }
                }
            }
        }

        int res = (maxrow - minrow + 1) * (maxcol - mincol + 1);
        return res;
    }
};
