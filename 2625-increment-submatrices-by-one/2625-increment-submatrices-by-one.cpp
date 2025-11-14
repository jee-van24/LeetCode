class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>mat(n,vector<int>(n,0));
        for(auto v:queries){
            int r1=v[0],c1=v[1],r2=v[2],c2=v[3];
            for(int i=r1;i<=r2;i++){
                for(int j=c1;j<=c2;j++){
                    mat[i][j]+=1;
                }
            }
        }
        return mat;
    }
};