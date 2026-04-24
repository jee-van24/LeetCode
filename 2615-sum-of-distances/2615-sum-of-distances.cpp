class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, long long> freqcnt, idxsum;
        vector<long long> res(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            auto freq = 1ll*freqcnt[nums[i]];
            auto sum = 1ll*idxsum[nums[i]];
            res[i] += 1ll*freq*i-sum;
            freqcnt[nums[i]] += 1;
            idxsum[nums[i]] += i;
        }
        idxsum.clear();
        freqcnt.clear();
        for (int i = nums.size() - 1; i >= 0; i--) {
            auto freq = 1ll*freqcnt[nums[i]];
            auto sum = 1ll*idxsum[nums[i]];
            res[i] += 1ll*sum-freq*i;
            freqcnt[nums[i]] += 1;
            idxsum[nums[i]] += i;
        }
        return res;
    }
};