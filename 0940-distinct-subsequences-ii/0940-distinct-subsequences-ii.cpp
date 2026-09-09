class Solution {
public:
    const int mod = 1e9 + 7;

    int solve(int i, string& s, vector<int>& dp, vector<int>& prevIndex) {
        if(i < 0) {
            return 1;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int total = 2LL * solve(i - 1, s, dp, prevIndex) % mod;

        int prev = prevIndex[i];

        if(prev != -1) {
            int dup = solve(prev - 1, s, dp, prevIndex);
            total = (total - dup + mod) % mod;
        }

        return dp[i] = total;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        vector<int> dp(n, -1);
        vector<int> prevIndex(n, -1);

        vector<int> lastseen(26, -1);

        for(int i = 0; i < n; i++) {
            int ch = s[i] - 'a';

            prevIndex[i] = lastseen[ch];
            lastseen[ch] = i;
        }

        int res = solve(n - 1, s, dp, prevIndex);

        return (res - 1 + mod) % mod;
    }
};