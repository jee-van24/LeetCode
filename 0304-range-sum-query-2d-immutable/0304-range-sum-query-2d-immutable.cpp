class NumMatrix {
public:
    vector<vector<int>>prefix;
    NumMatrix(vector<vector<int>>& matrix) { 
        for(int i=0;i<matrix.size();i++){
            vector<int>temp;
            temp.push_back(matrix[i][0]);
            for(int j=1;j<matrix[0].size();j++){
                temp.push_back(matrix[i][j]+temp[j-1]);
            }
            prefix.push_back(temp);
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        int l1=col1,l2=col2;
        for(int i=row1;i<=row2;i++){
            if(col1==0){
                sum+=prefix[i][l2];
            }else{
                sum+=prefix[i][l2]-prefix[i][col1-1];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */