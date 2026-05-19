class Solution {
public:
    int minJumps(vector<int>& arr) {
        int res = 0;
        if (arr.size() == 1)
            return 0;
        vector<bool> visited(arr.size(), false);
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (q.size()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int idx = q.front();
                if (idx == arr.size() - 1)
                    return res;
                q.pop();
                if (idx >0 && visited[idx-1] == false) {
                    q.push(idx-1);
                    visited[idx-1]=true;
                }
                if(idx<arr.size()&&visited[idx+1]==false){
                    q.push(idx+1);
                    visited[idx+1]=true;
                }
                for(auto n:map[arr[idx]]){
                    if(visited[n]==false){
                        q.push(n);
                        visited[n]=true;
                    }
                }
                map[arr[idx]].clear();
            }
            
            res++;
        }
        return res;
    }
};