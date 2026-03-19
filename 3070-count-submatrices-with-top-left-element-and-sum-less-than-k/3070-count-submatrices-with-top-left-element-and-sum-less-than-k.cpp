class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();

        int res = 0;

        vector<int> col(c, 0);

        for(int i = 0; i < r; i++) {

            // build column sums from row 0 → i
            for(int j = 0; j < c; j++) {
                col[j] += grid[i][j];
            }

            int s = 0;

            // count submatrices (0,0) → (i,j)
            for(int j = 0; j < c; j++) {
                s += col[j];
                if(s <= k) res++;
                else break;  // valid since all values ≥ 0
            }
        }

        return res;
    }
};