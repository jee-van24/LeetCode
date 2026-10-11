class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {

        unordered_map<int,int> diffMap;

        for(int i = 0; i < nums1.size(); i++) {
            int currdiff = abs(nums1[i] - nums2[i]);
            diffMap[currdiff]++;
        }

        int k = k1 + k2;

        for(int currdiff = 1e5; currdiff > 0 && k > 0; currdiff--) {

            int totalOps = min(diffMap[currdiff], k);

            diffMap[currdiff] -= totalOps;
            diffMap[currdiff - 1] += totalOps;

            k -= totalOps;
        }

        long long res = 0;

        for(int d = 1; d <= 1e5; d++) {
            res += 1LL * diffMap[d] * d * d;
        }

        return res;
    }
};