class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res=0;
        auto prev=points[0];
        for(int i=1;i<points.size();i++){
            auto curr=points[i];
            if(abs(curr[0]-prev[0])==abs(curr[1]-prev[1])){
                res+=abs(curr[0]-prev[0]);
            }else if(abs(curr[0]-prev[0])!=abs(curr[1]-prev[1])){
                if(curr[0]==prev[0]){
                    res+=abs(curr[1]-prev[1]);
                }else if(curr[1]==prev[1]){
                    res+=abs(curr[0]-prev[0]);
                }else{
                    res+=min(abs(curr[0]-prev[0]),abs(curr[1]-prev[1]));
                    res+=abs(abs(curr[0]-prev[0])-abs(curr[1]-prev[1]));
                }
            }
            prev=curr;
        }
        return res;
    }
};