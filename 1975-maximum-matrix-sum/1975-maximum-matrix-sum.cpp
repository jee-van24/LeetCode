class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res=0;
        int  mn=INT_MAX;
        long long negcnt=0;
        bool f=false;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)f=true;
                res+=abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    negcnt++;
                }
                mn=min(mn,abs(matrix[i][j]));
            }
        }
        cout<<mn;
        if(negcnt%2==0){
            return res;
        }else{
            if(!f)
            res-=2*mn;
        }
        return res;
    }
};