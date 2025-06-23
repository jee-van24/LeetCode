class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(auto row :grid){
            for(auto num:row){
                if(num<0){
                    count++;
                }
            }
        }
        return count;
    }
};