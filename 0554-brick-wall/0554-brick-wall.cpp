class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int>prefixEdge;
        int max_edges=0;
        for(auto &row:wall){
            long long psum=0;
            for(int i=0;i<row.size()-1;i++){
                psum+=row[i];
                prefixEdge[psum]++;
                max_edges=max(max_edges,prefixEdge[psum]);
            }
        }
        return wall.size()-max_edges;
    }
};