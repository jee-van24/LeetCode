class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    int rones=0;
                    //check the row 
                    for(int c=0;c<mat[0].size();c++){
                        if(mat[i][c]==1)rones++;
                    }
                    if(rones!=1)break;
                    //check col
                    int cones=0;
                    for(int r=0;r<n;r++){
                        if(mat[r][j]==1)cones++;
                    }
                    if(cones==1&&rones==1)res++;
                }
            }
        }
        return res;
    }
};