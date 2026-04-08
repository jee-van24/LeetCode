class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res=0;
        for(int i=0;i<points.size();i++){
            unordered_map<int,int>map;
            int x=points[i][0],y=points[i][1];
            for(int j=0;j<points.size();j++){
                if(i==j)continue;
                int curx=points[j][0],cury=points[j][1];
                int dist=(curx-x)*(curx-x)+(cury-y)*(cury-y);
                map[dist]++;
            }
            for(auto &p:map){
                res+=(p.second)*(p.second-1);
            }
        }
        return res;
    }
};