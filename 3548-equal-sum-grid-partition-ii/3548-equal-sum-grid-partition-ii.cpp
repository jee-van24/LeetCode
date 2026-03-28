class Solution {
public:
    bool safeRemove(int rows, int cols, int r, int c, int rStart, int rEnd, int cStart, int cEnd) {
        if(rows > 1 && cols > 1) return true;

        if(rows == 1){
            return (c == cStart || c == cEnd);
        }

        if(cols == 1){
            return (r == rStart || r == rEnd);
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        unordered_map<int,long long> rowp, colp;
        long long s = 0;

        unordered_map<long long, vector<pair<int,int>>> rowdiff;
        unordered_map<long long, vector<pair<int,int>>> coldiff;

        int n = grid.size(), m = grid[0].size();


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                s += grid[i][j];
                rowdiff[grid[i][j]].push_back({i,j});
            }
            rowp[i] = s;
        }


        s = 0;
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                s += grid[i][j];
                coldiff[grid[i][j]].push_back({i,j});
            }
            colp[j] = s;
        }

        long long total = rowp[n-1];

       for(int i = 0; i < n-1; i++){
            long long x = rowp[i];
            long long y = total - x;

            if(x == y) return true;

            long long d = abs(x - y);

            if(x < y){
                // need d in bottom
                if(rowdiff.count(d)){
                    for(auto &p : rowdiff[d]){
                        if(p.first > i){
                            int rows = n - (i+1);
                            int cols = m;
                            if(safeRemove(rows, cols, p.first, p.second, i+1, n-1, 0, m-1))
                                return true;
                        }
                    }
                }
            } else {
                // need d in top
                if(rowdiff.count(d)){
                    for(auto &p : rowdiff[d]){
                        if(p.first <= i){
                            int rows = i+1;
                            int cols = m;
                            if(safeRemove(rows, cols, p.first, p.second, 0, i, 0, m-1))
                                return true;
                        }
                    }
                }
            }
        }

        // 🔹 COLUMN CUT
        for(int j = 0; j < m-1; j++){
            long long x = colp[j];
            long long y = total - x;

            if(x == y) return true;

            long long d = abs(x - y);

            if(x < y){
                // need d in right
                if(coldiff.count(d)){
                    for(auto &p : coldiff[d]){
                        if(p.second > j){
                            int rows = n;
                            int cols = m - (j+1);
                            if(safeRemove(rows, cols, p.first, p.second, 0, n-1, j+1, m-1))
                                return true;
                        }
                    }
                }
            } else {
                // need d in left
                if(coldiff.count(d)){
                    for(auto &p : coldiff[d]){
                        if(p.second <= j){
                            int rows = n;
                            int cols = j+1;
                            if(safeRemove(rows, cols, p.first, p.second, 0, n-1, 0, j))
                                return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};