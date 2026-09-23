class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        vector<int> pleft(n, 0);

        pleft[0] = nums[0];

        for(int i = 1; i < n; i++) {
            pleft[i] = pleft[i - 1] + nums[i];
        }

        unordered_map<int, int> suffix;

        int sum = 0;

        for(int i = n - 1; i >= 0; i--) {

            sum += nums[i];

            int rightCount = n - i;

            suffix[sum] = rightCount;
        }

        int res = INT_MAX;

        for(int leftCount = 0; leftCount <= n; leftCount++) {

            int leftSum = 0;

            if(leftCount > 0)
                leftSum = pleft[leftCount - 1];

            if(leftSum > x)
                break;

            int needed = x - leftSum;

            if(needed == 0) {
                res = min(res, leftCount);
                continue;
            }
            if(suffix.count(needed)) {

                int rightCount = suffix[needed];

                if(leftCount + rightCount <= n) {
                    res = min(res, leftCount + rightCount);
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};