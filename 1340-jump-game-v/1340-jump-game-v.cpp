class Solution {
public:
    int solve(int idx, vector<int>& arr, vector<int>& dp, int d) {
        if (dp[idx] != -1) {
            // already reached this idx and i have the best answer stored
            // already so dont recompute the same state
            return dp[idx];
        }
        int ans = 1; // already jumped to the current idx
        for (int j = idx + 1; j <= min((int)arr.size() - 1, idx + d); j++) {
            if (arr[j] >= arr[idx])
                break;
            // its a valid jump, call the next recursive call
            ans = max(ans, 1 + solve(j, arr, dp, d));
        }
        for (int j = idx - 1; j >= max(0, idx - d); j--) {
            if (arr[j] >= arr[idx])
                break;
            ans = max(ans, 1 + solve(j, arr, dp, d));
        }
        return dp[idx] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(
                res, solve(i, arr, dp, d)); // already jumped to the current idx
        }
        return res;
    }
};