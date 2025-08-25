class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>res;
        vector<vector<int>>diagonals(m+n-1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diagonals[i+j].push_back(mat[i][j]);
            }
        }
        for(int d=0;d<diagonals.size();d++){
            if(d%2==0){
                reverse(diagonals[d].begin(),diagonals[d].end());
            }
        }
        for(auto vec:diagonals){
            for(auto val:vec){
                res.push_back(val);
            }
        }
        return res;
    }
};