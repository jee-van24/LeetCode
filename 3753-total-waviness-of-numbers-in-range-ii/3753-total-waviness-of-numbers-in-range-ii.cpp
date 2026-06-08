class Solution {
public:

    pair<long long, long long>
    dp[20][11][11][2];

    bool seen[20][11][11][2];

    pair<long long, long long>
    solve(string &num,
          int pos,
          int prev,
          int prevprev,
          bool IsBound,
          bool isLeadingZero) {

        // formed complete number
        if (pos == num.size()) {
            return {1, 0};
        }

        // use memoized answer
        if (!IsBound &&
            seen[pos]
                [prev + 1]
                [prevprev + 1]
                [isLeadingZero]) {

            return dp[pos]
                     [prev + 1]
                     [prevprev + 1]
                     [isLeadingZero];
        }

        int limdig =
            IsBound ? num[pos] - '0' : 9;

        long long totalnos = 0;

        long long totwaviness = 0;

        for (int d = 0; d <= limdig; d++) {

            bool newIsBound =
                (IsBound && d == limdig);

            bool newIsLeadingZero =
                (isLeadingZero && d == 0);

            int newprev = prev;

            int newprevprev = prevprev;

            int contribute = 0;

            if (!newIsLeadingZero) {

                // check whether prev becomes
                // peak or valley

                if (prev != -1 &&
                    prevprev != -1) {

                    bool valley =
                        (prev < d &&
                         prev < prevprev);

                    bool peak =
                        (prev > d &&
                         prev > prevprev);

                    if (peak || valley) {
                        contribute = 1;
                    }
                }

                // shift digit history
                newprev = d;

                newprevprev = prev;
            }

            auto [temptotalnos,
                  tempwaviness]

                = solve(num,
                        pos + 1,
                        newprev,
                        newprevprev,
                        newIsBound,
                        newIsLeadingZero);

            totalnos += temptotalnos;

            totwaviness +=
                tempwaviness +
                (1LL *
                 temptotalnos *
                 contribute);
        }

        pair<long long, long long> ans =
            {totalnos, totwaviness};

        // memoize only non-tight states
        if (!IsBound) {

            seen[pos]
                [prev + 1]
                [prevprev + 1]
                [isLeadingZero] = true;

            dp[pos]
              [prev + 1]
              [prevprev + 1]
              [isLeadingZero] = ans;
        }

        return ans;
    }

    long long calc(long long num) {

        if (num <= 0)
            return 0;

        // fresh memoization for each bound
        memset(seen, false, sizeof(seen));

        string n = to_string(num);

        auto [totalnos, sum]

            = solve(n,
                    0,
                    -1,
                    -1,
                    true,
                    true);

        return sum;
    }

    long long totalWaviness(long long num1,
                            long long num2) {

        long long ans1 = calc(num1 - 1);

        long long ans2 = calc(num2);

        return ans2 - ans1;
    }
};