class Solution {
public:
    bool is_diff_possible(vector<int>& nums, int current_diff, int p) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] <= current_diff) {
                count++;
                i++;
            }
            if (count >= p) {
                return true;
            }
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int low = 0, high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        sort(nums.begin(), nums.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (is_diff_possible(nums, mid, p) == true) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};