class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int res=INT_MAX;
        for(auto pair:tasks){
            int sum=pair[0]+pair[1];
            res=min(res,sum);

        }
        return res;

    }
};