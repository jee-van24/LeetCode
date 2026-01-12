class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res=0;
        auto prev=points[0];
        for(int i=1;i<points.size();i++){
            auto curr=points[i];
            int dx=abs(curr[0]-prev[0]);
            int dy=abs(curr[1]-prev[1]);
            if(dx==dy){
                res+=dx;
            }else{
                if(curr[0]==prev[0]){
                    res+=dy;
                }else if(curr[1]==prev[1]){
                    res+=dx;
                }else{
                    if(dx<dy){
                        res+=dx;
                        res+=abs(dx-dy);
                    }else{
                        res+=dy;
                        res+=abs(dx-dy);
                    }
                }
            }
            prev=curr;
        }
        return res;
    }
};