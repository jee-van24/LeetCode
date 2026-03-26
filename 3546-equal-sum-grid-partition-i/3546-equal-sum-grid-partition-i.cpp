class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        unordered_map<int,long long>rowp;
        long long s=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                s+=grid[i][j];
            }
            rowp[i]=s;
        }
        unordered_map<int,long long>colp;
         s=0;
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                s+=grid[j][i];
            }
            colp[i]=s;
        }
        for(int i=0;i<grid.size();i++){
            long long  x=rowp[i];
            long long  y=rowp[grid.size()-1]-x;
            if(x==y)return true;
        }
        for(int i=0;i<grid[0].size();i++){
            long long x=colp[i];
            long long y=colp[grid[0].size()-1]-x;
            if(x==y)return true;
        }
        return false;

    }
};