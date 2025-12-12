class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,vector<int>>mapx;
        unordered_map<int,vector<int>>mapy;
        for(auto coord:buildings){
            int cx=coord[0];
            int cy=coord[1];
            if(!mapx.count(cx)){
                mapx[cx].push_back(cy);
                mapx[cx].push_back(cy);
            }else{
                mapx[cx][1]=max(cy,mapx[cx][1]);
                mapx[cx][0]=min(cy,mapx[cx][0]);
            }
            if(!mapy.count(cy)){
                mapy[cy].push_back(cx);
                mapy[cy].push_back(cx);
            }else{
                mapy[cy][1]=max(mapy[cy][1],cx);
                mapy[cy][0]=min(mapy[cy][0],cx);
            }
        }
        int res=0;
        for(auto c:buildings){
            int x=c[0],y=c[1];
            if(mapx[x][0]<y&&y<mapx[x][1]){
                if(mapy[y][0]<x&&x<mapy[y][1]){
                    res++;
                }
            }
        }
        return res;
    }
};