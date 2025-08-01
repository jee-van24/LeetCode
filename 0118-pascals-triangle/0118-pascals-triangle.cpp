class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        int n=numRows;
        res.push_back({1});
        for(int i=1;i<n;i++){
             vector<int>temp;
             int sum=0;
             temp.push_back(1);
             for (int j=1; j<res[i -1].size();j++) {
                 sum=res[i-1][j-1]+res[i-1][j];
                 temp.push_back(sum);
             }
             temp.push_back(1);
             res.push_back(temp);   
        }
            
        return res;
    }
};