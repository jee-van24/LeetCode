class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();

        // dp[i][0] -> maximum score Alice can get from index i when it is Alice's turn
        // dp[i][1] -> maximum score Alice can get from index i when it is Bob's turn
        vector<vector<int>> dp(n + 3, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {

            // Alice's turn , she wants to maximize her score
            int take1 = nums[i] + dp[i + 1][1];

            int take2 = INT_MIN;
            if (i + 1 < n) {
                take2 = nums[i] + nums[i + 1] + dp[i + 2][1];
            }

            int take3 = INT_MIN;
            if (i + 2 < n) {
                take3 = nums[i] + nums[i + 1] + nums[i + 2]
                        + dp[i + 3][1];
            }

            dp[i][0] = max({take1, take2, take3});


            // Bob's turn , whatever he takes contributes nothing to Alice's score
            // and Bob wants to minimize Alice's final score

            int skip1 = dp[i + 1][0];

            int skip2 = INT_MAX;
            if (i + 1 < n) {
                skip2 = dp[i + 2][0];
            }

            int skip3 = INT_MAX;
            if (i + 2 < n) {
                skip3 = dp[i + 3][0];
            }

            dp[i][1] = min({skip1, skip2, skip3});
        }

        int alice = dp[0][0];
        int total = accumulate(nums.begin(), nums.end(), 0);
        int bob = total - alice;

        if (alice > bob)
            return "Alice";
        else if (alice < bob)
            return "Bob";

        return "Tie";
    }
};