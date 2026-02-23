class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>res(n,0);
        stack<vector<int>>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&s.top()[1]<=temperatures[i]){
                s.pop();
            }
            if(!s.empty()){
                res[i]=s.top()[0]-i;
            }
            s.push({i,temperatures[i]});
        }
        return res;
    }
};