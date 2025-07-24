class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>jobs;
        int n=difficulty.size();
        for(int i=0;i<n;i++){
            jobs.push_back({difficulty[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());
        int i=0;
        int curr_profit=0;
        int res=0;
        for(auto w:worker){
            while(i<n&&jobs[i].first<=w){
                curr_profit=max(curr_profit,jobs[i].second);
                i++;
            }
            res+=curr_profit;
        }
        return res;
    }
};