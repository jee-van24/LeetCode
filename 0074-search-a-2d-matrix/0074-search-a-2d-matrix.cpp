class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool flag=false;
        for(auto row: matrix){
            for(auto val: row){
                if(val==target){
                    flag=true;
                }
            }
        }
        return flag;
    }    
};