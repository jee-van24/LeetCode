class Solution {
public:
    void dfs(int n,unordered_map<int,unordered_set<int>>&calls,unordered_set<int>&sus){
        if(sus.count(n)){
            return ;
        }
        sus.insert(n);
        for(auto num:calls[n]){
            dfs(num,calls,sus);
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        unordered_set<int> sus;
        unordered_map<int, unordered_set<int>> calls;
        unordered_set<int> temp;
        for (int i = 0; i < n; i++) {
            temp.insert(i);
        }
        for (auto v : invocations) {
            calls[v[0]].insert(v[1]);
        }
        dfs(k,calls,sus);
        unordered_set<int> notsus;
        for (int i = 0; i < n; i++) {
            if (!sus.count(i)) {
                notsus.insert(i);
            }
        }
        // now all  of the non sus should not invoke even 1 method which is sus
        bool f = true;
        for (auto n : notsus) {
            f = true;
            for (auto num : calls[n]) {
                if (sus.count(num)) {
                    f = false;
                    break;
                }
            }
            if (!f) {
                break;
            }
        }
        if (!f) {
            return vector<int>(temp.begin(), temp.end());
        }
        for (auto n : sus) {
            temp.erase(n);
        }
        return vector<int>(temp.begin(), temp.end());
    }
};