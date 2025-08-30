class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        long long res = 0;
        long long currsum = nums[0];
        int left = 0;
        map[nums[0]] = 1;
        if (k == 1) return *max_element(nums.begin(), nums.end());

        for (int right = 1; right < nums.size(); right++) {   // ✅ fix #1
            if (map.find(nums[right]) == map.end()) {
                map[nums[right]] = 1;
                currsum += nums[right];
            } else {
                while (map.find(nums[right]) != map.end()) {
                    currsum -= nums[left];
                    map[nums[left]]--;
                    if (map[nums[left]] == 0) {
                        map.erase(nums[left]);
                    }
                    left++;
                }
                map[nums[right]] = 1;
                currsum += nums[right];
            }
            while (right - left + 1 > k) {
                currsum -= nums[left];
                map[nums[left]]--;
                if (map[nums[left]] == 0) {
                    map.erase(nums[left]);
                }
                left++;
            }
            if (right - left + 1 == k && map.size() == k) {
                res = max(res, currsum);
            }
        }
        return res;
    }
};
