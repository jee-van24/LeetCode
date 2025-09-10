class Solution {
public:
    bool hasCommon(unordered_set<int>& a,unordered_set<int>& b) {
        unordered_set<int> st(a.begin(), a.end());
        for (int y : b) {
            if (st.count(y))
                return true; // found common
        }
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        unordered_map<int, unordered_set<int>> map;
        for (int i = 0; i < languages.size(); i++) {
            unordered_set<int>set(languages[i].begin(),languages[i].end());
            map[i + 1] =set;
        }
       /* for (auto p : map) {
            cout << p.first << " ";
            for (int n : p.second) {
                cout << n;
            }
            cout << endl;
        }
        */
        int res=INT_MAX;
        unordered_set<int> users;
        for (auto p : friendships) {
            auto v1 = map[p[0]];
            auto v2 = map[p[1]];
            if (!hasCommon(v1, v2)) {
                users.insert(p[0]);
                users.insert(p[1]);
            }
        }
        // now set will have all the users who might have to learn a lang;
        for (int i = 1; i <= n; i++) {
            int commonlang = i;
            int count = 0;
            for (auto user :users) {
                auto lang=map[user];
                if(!map[user].count(commonlang)){
                    count++;
                }
            }
            res = min(res, count);
        }
        return res;
    }
};