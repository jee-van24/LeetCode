class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        unordered_map<int,unordered_map<int,pair<int,int>>>map;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<c;i++){
            int xcnt=0,ycnt=0;
            for(int j=0;j<r;j++){
                if(grid[j][i]=='X'){
                    xcnt++;
                }else if(grid[j][i]=='Y'){
                    ycnt++;
                }
                map[i][j].first=xcnt;
                map[i][j].second=ycnt;
            }
        }
        
        int res=0;
        for(int i=0;i<r;i++){
            int xcnt=map[0][i].first;
            int ycnt=map[0][i].second;
            if(xcnt>0&&xcnt==ycnt){
                res++;
            }
            for(int j=1;j<c;j++){
                xcnt+=map[j][i].first;
                ycnt+=map[j][i].second;
                if(xcnt>0&&xcnt==ycnt){
                    res++;
                }
            }
        }
        return res;
    }
};