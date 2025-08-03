class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int res = 0;
        int zeroes = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zeroes++;
            }
            while (zeroes > k) {
                if (nums[left] == 0) {
                    zeroes--;
                }
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};