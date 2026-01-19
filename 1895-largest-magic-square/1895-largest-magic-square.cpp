class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int res=1;
        int len=min(grid.size(),grid[0].size());//cause you need a k*k
        for(int k=2;k<=len;k++){
            for(int row=0;row+k<=grid.size();row++){
                for(int col=0;col+k<=grid[0].size();col++){
                    vector<int>sums;
                    for(int i=0;i<k;i++){
                        int s=0;
                        for(int j=0;j<k;j++){
                            s+=grid[row+i][col+j];
                        }
                        sums.push_back(s);

                    }
                    //col sum
                    for(int j=0;j<k;j++){
                        int s=0;
                        for(int i=0;i<k;i++){
                            s+=grid[row+i][col+j];
                        }
                        sums.push_back(s);
                    }
                    //diagonals 
                    int s=0;
                    for(int d=0;d<k;d++){
                        s+=grid[row+d][col+d];
                    }
                    sums.push_back(s);
                    s=0;
                    for(int d=0;d<k;d++){
                        s+=grid[row+d][col+k-1-d];
                    }
                    sums.push_back(s);
                    bool f=true;
                    for(int i=1;i<sums.size();i++){
                        if(sums[i]!=sums[i-1]){
                            f=false;
                            break;
                        }
                    }
                    if(f){
                        res=max(res,k);
                    }            
                }
            }
        }
        return res;
    }
};