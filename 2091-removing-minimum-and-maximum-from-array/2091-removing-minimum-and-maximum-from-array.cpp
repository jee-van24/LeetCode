class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int l1 = -1;
        int l2 = -1;
        int minval = INT_MAX;
        int maxval = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                l1 = i;
                l2 = i;
                minval = nums[i];
                maxval = nums[i];
                continue;
            }
            if (nums[i] < minval) {
                minval = nums[i];
                l1 = i;
            }
            if (nums[i] > maxval) {
                maxval = nums[i];
                l2 = i;
            }
        }

        int n = nums.size();

        int r1 = n - l1 - 1;
        int r2 = n - l2 - 1;

        int res1 = max(l1, l2) + 1;                   // both from left
        int res2 = max(r1, r2) + 1;                   // both from right
        int res3 = min(l1, l2) + 1 + min(r1, r2) + 1; // one from each side

        return min({res1, res2, res3});
    }
};