class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long> prevRem(k, 0);
        vector<long long> res(k, 0);

        for(int i = 0; i < nums.size(); i++) {

            int currEleRem = nums[i] % k;

            vector<long long> currRem(k, 0);

            // Subarray containing only nums[i]
            currRem[currEleRem] = 1;

            // Extend previous subarrays
            for(int oldRem = 0; oldRem < k; oldRem++) {
                int newRem = (1LL * oldRem * currEleRem) % k;
                currRem[newRem] += prevRem[oldRem];
            }

            // Add all subarrays ending at i
            for(int x = 0; x < k; x++) {
                res[x] += currRem[x];
            }

            // Current -> previous
            prevRem = move(currRem);
        }

        return res;
    }
};