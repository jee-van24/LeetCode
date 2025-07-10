class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>>check;
        vector<vector<int>>res;
        for(auto pair: points){
            int x=pair[0];
            int y=pair[1];
            int dist= (x*x)+(y*y);
            check.push_back({dist,pair});
        }
        sort(check.begin(),check.end());
        for(int i=0;i<k;i++){
            vector<int>temp=check[i].second;
            res.push_back({temp});
        }
        return res;
    }
};