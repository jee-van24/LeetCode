class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> freq;
        int count = 0;

        for (auto& row : grid) {
            freq[row]++;
        }

        int n = grid.size();
        for (int i = 0; i < n; i++) {
            vector<int> col(n); 
            for (int j = 0; j < n; j++) {
                col[j] = grid[j][i]; 
            }
            if (freq.find(col) != freq.end()) {
                count += freq[col];
            }
        }

        return count;
    }
};
