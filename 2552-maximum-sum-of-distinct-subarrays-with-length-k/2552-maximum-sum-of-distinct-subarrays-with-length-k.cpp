class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return 0;

        unordered_map<int,int> freq;
        long long res = 0;
        long long currsum = 0;

        for (int i = 0; i < n; i++) {
            currsum += nums[i];
            freq[nums[i]] = freq[nums[i]] + 1;
            if (i >= k) {
                int out = nums[i - k];
                freq[out] = freq[out] - 1;
                if (freq[out] == 0) {
                    freq.erase(out);
                }
                currsum -= out;
            }

            
            if (i >= k - 1) {
                if (freq.size() == k) {
                    if (currsum > res) {
                        res = currsum;
                    }
                }
            }
        }
        return res;
    }
};
