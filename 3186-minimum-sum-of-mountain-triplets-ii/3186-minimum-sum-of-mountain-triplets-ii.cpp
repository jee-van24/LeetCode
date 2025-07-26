class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, INT_MAX);
        vector<int> right(n, INT_MAX);

        int minLeft = nums[0];
        for (int i = 1; i < n; i++) {
            left[i] = minLeft;
            minLeft = min(minLeft, nums[i]);
        }

        int minRight = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = minRight;
            minRight = min(minRight, nums[i]);
        }

        int res = INT_MAX;
        for (int j = 1; j < n - 1; j++) {
            if (left[j] < nums[j] && nums[j] > right[j]) {
                res = min(res, left[j] + nums[j] + right[j]);
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
