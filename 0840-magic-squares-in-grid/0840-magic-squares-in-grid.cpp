class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        for (int i = 0; i< row; i++) {
            for (int j = 0; j < col; j++) {
                // in this level , take all the matrices
                if (i + 2 < row && j + 2 < col) {
                    // this matrice is in bounds
                    // before takings sums of rows and cols, check if no num is
                    // >10
                    unordered_set<int> s;
                    bool f = true;
                    for (int currow = i; currow <=i+2; currow++) {
                        for (int currcol = j; currcol<=j+2; currcol++) {
                            if (grid[currow][currcol] <= 0 ||
                                grid[currow][currcol] > 9) {
                                f = false;
                                break;
                            }else if(s.count(grid[currow][currcol])){
                                f=false;
                                break;
                            }
                            s.insert(grid[currow][currcol]);
                        }
                    }
                    if (f) {
                        vector<int> sums;
                        // sum of all 3 rows
                        for (int currow = i; currow <= i + 2; currow++) {
                            sums.push_back(grid[currow][j] +
                                           grid[currow][j + 1] +
                                           grid[currow][j + 2]);
                        }
                        // sum of all 3 cols
                        for (int currcol = j; currcol <= j+ 2;
                             currcol++) {
                            sums.push_back(grid[i][currcol] +
                                           grid[i + 1][currcol] +
                                           grid[i + 2][currcol]);
                        }
                        // sum of the diagonals
                        sums.push_back(grid[i][j] + grid[i + 1][j + 1] +
                                       grid[i + 2][j + 2]);
                        sums.push_back(grid[i + 2][j] + grid[i + 1][j + 1] +
                                       grid[i][j + 2]);
                        bool f1=true;
                        for (int i = 1; i < sums.size(); i++) {
                            if (sums[i] != sums[i - 1]) {
                                f1=false;
                                break;
                            }
                        }
                        if(f1){
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};