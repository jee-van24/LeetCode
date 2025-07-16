class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd_count = 0, even_count = 0;
        int odd_even_count = 1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                even_count++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1) {
                odd_count++;
            }
        }
        int rem = nums[0] % 2;
        rem = 1 - rem;

        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == rem) {
                odd_even_count++;
                rem = 1 - rem;
            }
        }

        return max({odd_count, even_count, odd_even_count});
    }
};
