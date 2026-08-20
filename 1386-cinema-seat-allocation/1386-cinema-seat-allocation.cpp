class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // things to note while solving this prob that i have observed after 40
        // mins
        /*
            1.you can only place 2 groups at max given that it matched all the
           conditions which are the firsr group and the last group
            2. 2nd and 3rd seat belong to first group exclusively and 8 9 belong
           to third group , the remaining 4 5 6 7 are shared ,so you gotta
           handle that intersection correctly

        */
        unordered_set<int> reservedRows;
        unordered_map<int, unordered_set<int>> map1;
        for (auto& p : reservedSeats) {
            reservedRows.insert(p[0]);
            map1[p[0]].insert(p[1]);
        }
        unordered_map<int, unordered_set<int>> map2;
        for (auto& p : map1) {
            auto set = p.second;
            for (int i = 2; i <= 9; i++) {
                if ((i == 2 || i == 3) && set.count(i)) {
                    // group 1
                    map2[p.first].insert(1);
                } else if ((i == 8 || i == 9) && set.count(i)) {
                    // group 2
                    map2[p.first].insert(3);
                } else {
                    if (set.count(i)) {
                        map2[p.first].insert(2);
                        if (i == 4 || i == 5) {
                            map2[p.first].insert(1);
                        } else {
                            map2[p.first].insert(3);
                        }
                    }
                }
            }
        }
        int res = 2 * n;
        for (auto n : reservedRows) {
            auto& s = map2[n];
            if (s.count(1) && s.count(2) && s.count(3)) {
                // {1,2,3}  all blocked -> 0 families
                res -= 2;

            } else if (!s.count(1) && !s.count(2) && !s.count(3)) {
                // {} nothing blocked  2 families
                res -= 0;

            } else if (s.count(1) && !s.count(2) && !s.count(3)) {
                // {1} -> only left blocked 1 family
                res -= 1;

            } else if (!s.count(1) && s.count(2) && !s.count(3)) {
                // {2}  only middle blocked left + right -> 2 families
                res -= 0;

            } else if (!s.count(1) && !s.count(2) && s.count(3)) {
                // {3}  only right blocked  1 family
                res -= 1;

            } else if (s.count(1) && s.count(2) && !s.count(3)) {
                // {1,2}  only right available  1 family
                res -= 1;

            } else if (!s.count(1) && s.count(2) && s.count(3)) {
                // {2,3} only left available  1 family
                res -= 1;

            } else if (s.count(1) && !s.count(2) && s.count(3)) {
                // {1,3}  only middle available  1 family
                res -= 1;
            }
        }

        return res;
    }
};