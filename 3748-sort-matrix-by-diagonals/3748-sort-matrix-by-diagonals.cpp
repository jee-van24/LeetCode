class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        map<int,vector<int>>diag;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int key=i-j;
                diag[key].push_back(grid[i][j]);
            }
        }
        for(auto &pair:diag){
            int key=pair.first;
            vector<int>&d=pair.second;
            if(key>=0){
                sort(d.begin(),d.end(),greater<int>());
            }else{
                sort(d.begin(),d.end());
            }
        }
        vector<vector<int>>res(n,vector<int>(n,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int key=i-j;
                res[i][j]=diag[key].front();
                diag[key].erase(diag[key].begin());
            }
        }
        return res;
    }
};