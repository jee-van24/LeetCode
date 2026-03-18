class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int res=0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>streak;
        for(int i=0;i<m;i++){
            vector<int>cols(n,0);
            streak.push_back(cols);
        }
        for(int i=0;i<n;i++){
            streak[0][i]=matrix[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    streak[i][j]=streak[i-1][j]+1;
                }else{
                    streak[i][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++){
            vector<int> row=streak[i];
            sort(row.begin(),row.end(),greater<int>());
            for(int j=0;j<n;j++){
                res=max(res,(j+1)*row[j]);
            }
        }
        return res;

        
    }

};