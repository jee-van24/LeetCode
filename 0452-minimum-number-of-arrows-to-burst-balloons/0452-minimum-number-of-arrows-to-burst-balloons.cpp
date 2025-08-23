class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
       sort(points.begin(),points.end());
       int res=0;
       for(int i=0;i<points.size()-1;i++){
            auto front=points[i];
            for(int j=i+1;j<points.size();j++){
                auto back=points[j];
                if(front[1]>=back[0]){
                    front[1]=min(front[1],back[1]);
                    continue;
                }
                res++; 
                i=j-1;
                break;
            }
            if(i==points.size()-1){
                res++;
            }
       }
       return res+1;
    }
};