class Solution {
public:

    // for each offset <= k
    // do kadanes with elements of group size k combined

    long long maxSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        vector<long long> pref(n + 1);
        for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + nums[i - 1];

        long long res = LLONG_MIN;

        for (int off = 0; off < k; ++off) {
            long long cur = 0;
            for (int i = off; i + k <= n; i += k) {
                cur += pref[i + k] - pref[i];
                res = max(res, cur);
                cur = max(cur, 0LL);
            }
        }

        return res;
        
    }
};