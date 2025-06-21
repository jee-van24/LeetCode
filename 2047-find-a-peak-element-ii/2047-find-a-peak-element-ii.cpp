class Solution {
public:
    int idx(vector<vector<int>>&mat,int &col){
        int max_element=INT_MIN;
        int idx=-1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]>max_element){
                max_element=mat[i][col];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0,high=mat[0].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int rowidx=idx(mat,mid);//passing the current col
            int left= (mid-1>=0)?mat[rowidx][mid-1]:-1;
            int right=(mid+1<mat[0].size())?mat[rowidx][mid+1]:-1;
            if(mat[rowidx][mid]>left&&mat[rowidx][mid]>right){
                return {rowidx,mid};
            }else if (mat[rowidx][mid]<left){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};