class Solution {
public:

    bool solve(int r, int c, int open,
               vector<vector<char>>& grid,
               vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        if(r >= m || c >= n)
            return false;

        // Process current character
        if(grid[r][c] == '(')
            open++;
        else
            open--;

        if(open < 0)
            return false;

        if(dp[r][c][open] != -1)
            return dp[r][c][open];

        if(r == m-1 && c == n-1)
            return dp[r][c][open] = (open == 0);

        bool ans =
            solve(r+1, c, open, grid, dp) ||
            solve(r, c+1, open, grid, dp);

        return dp[r][c][open] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if((m+n-1) % 2 == 1)
            return false;

        if(grid[0][0] == ')')
            return false;

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m+n, -1)
            )
        );

        return solve(0, 0, 0, grid, dp);
    }
};