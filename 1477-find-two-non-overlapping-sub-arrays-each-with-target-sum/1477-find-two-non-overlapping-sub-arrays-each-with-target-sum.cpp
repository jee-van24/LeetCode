class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        vector<int> minLenTillIdx(n, INT_MAX);

        int left = 0;
        int sum = 0;

        int res = INT_MAX;

        int bestminLen = INT_MAX;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {

                int currwindowlen = right - left + 1;

                if (left > 0 &&
                    minLenTillIdx[left - 1] != INT_MAX) {

                    res = min(
                        res,
                        currwindowlen + minLenTillIdx[left - 1]
                    );
                }

                bestminLen = min(currwindowlen, bestminLen);
            }

            minLenTillIdx[right] = bestminLen;
        }

        return res == INT_MAX ? -1 : res;
    }
};