class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int res=0;
        double len=0;
        for(auto pair:dimensions){
            double currlen=sqrt(pair[0]*pair[0]+pair[1]*pair[1]);
            int area=pair[0]*pair[1];
            if(currlen>len){
                res=area;
                len=currlen;
            }else if(currlen==len){
                res=max(area,res);
            }
        }
        return res;
    }
};