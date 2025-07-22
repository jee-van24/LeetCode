class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> seen;
        int res = 0, curr_sum = 0;

        for (int right = 0; right < nums.size(); right++) {
            int curr = nums[right];
            if (find(seen.begin(), seen.end(), curr) != seen.end()) {
                while (find(seen.begin(), seen.end(), curr) != seen.end()) {
                    curr_sum -= seen.front();
                    seen.erase(seen.begin());
                }
            }

            seen.push_back(curr);
            curr_sum += curr;
            res = max(res, curr_sum);
        }

        return res;
    }
};
