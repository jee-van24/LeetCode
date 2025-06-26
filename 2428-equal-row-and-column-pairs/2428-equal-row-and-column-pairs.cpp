class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();

        for (auto& row : grid) {
            for (int col = 0; col < n; col++) {
                bool isEqual = true;
                for (int j = 0; j < n; j++) {
                    if (row[j] != grid[j][col]) {
                        isEqual = false;
                        break;
                    }
                }
                if (isEqual) {
                    count++;
                }
            }
        }

        return count;
    }
};
