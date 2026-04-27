class Solution {
public:
    unordered_map<int, vector<vector<int>>> directions = {
        {1, {{0, 1}, {0, -1}}},
        {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},
        {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}},
        {6, {{0, 1}, {-1, 0}}}
    };
    bool dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<bool>>& visited) {
        if (i == grid.size()-1&& j == grid[0].size()- 1) {
            return true;
        }
        visited[i][j] = true;
        for (auto& currdir : directions[grid[i][j]]) {
            int newi = currdir[0] + i;
            int newj = currdir[1] + j;
            if (newi < 0 || newi >= grid.size() || newj < 0 || newj >= grid[0].size() ||
                visited[newi][newj] == true) {
                continue;
            }
            // can go to the new ith and jth cell , lets see if u can go back to
            // the old ith and jth cell back from the new cell though
            for (auto& prevdir : directions[grid[newi][newj]]) {
                int tempi = prevdir[0];
                int tempj = prevdir[1];
                if (tempi + newi == i && tempj + newj == j) {
                    if (dfs(newi, newj, grid, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector < vector<bool>>visited(m, vector<bool>(n, false));

        return dfs(0, 0, grid, visited);
    }
};