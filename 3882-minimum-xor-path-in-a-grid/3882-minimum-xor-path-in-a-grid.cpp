class Solution {
public:

    vector<int> solve(int r, int c, vector<vector<int>>& grid,
                      vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        if (!dp[r][c].empty()) {
            return dp[r][c];
        }

        int curr = grid[r][c];

        // Reached destination
        if (r == m - 1 && c == n - 1) {
            dp[r][c].push_back(curr);
            return dp[r][c];
        }

        vector<bool> seen(1024, false);

        vector<int> down;
        vector<int> right;

        // Move down
        if (r + 1 < m) {
            down = solve(r + 1, c, grid, dp);
        }

        // Move right
        if (c + 1 < n) {
            right = solve(r, c + 1, grid, dp);
        }

        // Combine XOR values
        for (int x : down) {
            seen[curr ^ x] = true;
        }

        for (int x : right) {
            seen[curr ^ x] = true;
        }

        // Store achievable XOR values
        for (int i = 0; i < 1024; i++) {
            if (seen[i]) {
                dp[r][c].push_back(i);
            }
        }

        return dp[r][c];
    }

    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n)
        );

        vector<int> res = solve(0, 0, grid, dp);

        return *min_element(res.begin(), res.end());
    }
};