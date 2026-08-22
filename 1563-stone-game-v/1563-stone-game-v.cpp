class Solution {
public:
    int solve(int l, int r, vector<int>& psum, vector<vector<int>>& dp) {
        if (l == r) {
            return 0;
        }

        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        int temp = INT_MIN;

        for (int split = l; split < r; split++) {

            int lsum = psum[split] - (l > 0 ? psum[l - 1] : 0);
            int rsum = psum[r] - psum[split];

            if (lsum > rsum) {

                temp = max(temp, rsum + solve(split + 1, r, psum, dp));

            } else if (rsum > lsum) {

                temp = max(temp, lsum + solve(l, split, psum, dp));

            } else {

                temp = max(temp, lsum + max(solve(l, split, psum, dp),
                                            solve(split + 1, r, psum, dp)));
            }
        }

        return dp[l][r] = temp;
    }
    int stoneGameV(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> psum(n, 0);
        psum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            psum[i] = nums[i] + psum[i - 1];
        }
        int res = solve(0, n - 1, psum, dp);
        return res;
    }
};