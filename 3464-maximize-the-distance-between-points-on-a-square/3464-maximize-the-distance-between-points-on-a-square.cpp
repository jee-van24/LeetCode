class Solution {
public:
    bool check(vector<long long>& doubled, long long mid, int k, int n, int side){
        long long peri = 1LL * 4 * side;
        for(int i = 0; i < n; i++){
            int count = 1;
            int idx = i;
            long long lastpos = doubled[idx];

            for(int j = 2; j <= k; j++){
                long long targ = lastpos + mid;

                auto it = lower_bound(doubled.begin() + idx + 1,
                                      doubled.begin() + i + n,
                                      targ);

                if(it == doubled.begin() + i + n) break;

                idx = it - doubled.begin();
                lastpos = doubled[idx];
                count++;
            }

            if(count == k && doubled[i] - lastpos + peri >= mid){
                return true;
            }
        }
        return false;
    }

    long long get1d(int x, int y, int side){
        if(y == 0) return x;
        else if(x == side) return side + y;
        else if(y == side) return 3LL * side - x;
        else return 4LL * side - y;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        long long peri = 1LL * 4 * side;

        vector<long long> pos(n, 0);
        for(int i = 0; i < points.size(); i++){
            pos[i] = get1d(points[i][0], points[i][1], side);
        }

        sort(pos.begin(), pos.end());

        vector<long long> doubledpos(2 * n);
        for(int i = 0; i < n; i++){
            doubledpos[i] = pos[i];
            doubledpos[i + n] = pos[i] + peri;
        }

        long long res = 0;
        long long l = 0, r = 2LL * side;

        while(l <= r){
            long long mid = l + (r - l) / 2;

            if(check(doubledpos, mid, k, n, side)){
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return (int)res;
    }
};