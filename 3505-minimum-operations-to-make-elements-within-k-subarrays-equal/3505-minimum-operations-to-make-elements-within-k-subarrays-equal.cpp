class Solution {
public:
    int n, x, k;

    vector<long long> minOpsSubarray;
    vector<vector<long long>> memo;

    long long solve(int count, int i) {
        if (count == k)
            return 0;

        int elementsNeeded = (k - count) * x;

        if (i + elementsNeeded > n)
            return 1e16;

        if (memo[count][i] != -1)
            return memo[count][i];

        // Take current subarray
        long long result =
            minOpsSubarray[i] + solve(count + 1, i + x);

        // Skip current index
        result = min(result, solve(count, i + 1));

        return memo[count][i] = result;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        n = nums.size();
        this->x = x;
        this->k = k;

        minOpsSubarray.assign(n + 1, 0);
        memo.assign(k + 1, vector<long long>(n + 1, -1));

        multiset<int> left, right;
        long long leftSum = 0, rightSum = 0;

        int i = 0, j = 0;

        // Calculate minimum operations for every window of size x
        while (j < n) {

            if (left.size() <= right.size()) {
                left.insert(nums[j]);
                leftSum += nums[j];
            }
            else {
                right.insert(nums[j]);
                rightSum += nums[j];
            }

            // Balance the multisets
            if (!left.empty() && !right.empty()) {
                int maxLeft = *left.rbegin();
                int minRight = *right.begin();

                if (maxLeft > minRight) {
                    left.erase(left.find(maxLeft));
                    right.erase(right.find(minRight));

                    left.insert(minRight);
                    right.insert(maxLeft);

                    leftSum += minRight - maxLeft;
                    rightSum += maxLeft - minRight;
                }
            }

            // Process window of size x
            if (j - i + 1 == x) {

                int lsize = left.size();
                int rsize = right.size();

                int median = *left.rbegin();

                minOpsSubarray[i] =
                    (1LL * lsize * median - leftSum) +
                    (rightSum - 1LL * rsize * median);

                // Remove outgoing element
                auto it = left.find(nums[i]);

                if (it != left.end()) {
                    leftSum -= *it;
                    left.erase(it);
                }
                else {
                    auto it2 = right.find(nums[i]);
                    rightSum -= *it2;
                    right.erase(it2);
                }

                i++;
            }

            j++;
        }

        return solve(0, 0);
    }
};