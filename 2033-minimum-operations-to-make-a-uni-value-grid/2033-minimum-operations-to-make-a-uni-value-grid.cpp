class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                arr.push_back(grid[i][j]);
            }
        }
        int rem=arr[0]%x;
        for(int i=1;i<arr.size();i++){
            if(arr[i]%x!=rem)return -1;
        }
        sort(begin(arr),end(arr));
        int med=arr[arr.size()/2];
        int tot=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==med)continue;
            int k=abs((arr[i]-med)/x);
            tot+=k;
        }
        return tot;

    }
};