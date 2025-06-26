class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count =0;
        int n=grid.size();
        for(auto row : grid){
            for(int col=0;col<n;col++){
                vector<int>temp;
                for(int j=0;j<n;j++){
                    temp.push_back(grid[j][col]);
                }
                if(temp==row){
                    count++;
                }
            }
        }
        
        return count;
    }
};