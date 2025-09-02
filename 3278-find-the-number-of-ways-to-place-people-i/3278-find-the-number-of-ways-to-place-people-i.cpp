class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        auto cmp=[] (const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        };
        sort(points.begin(), points.end(),cmp);
        int res = 0;
        for(int i=0;i<points.size();i++){
            int lefty=points[i][1],maxy=-1;
            for(int j=i+1;j<points.size();j++){
                int righty=points[j][1];
                if(lefty>=righty&&righty>maxy){
                    res++;
                    maxy=righty;
                }
            }
        }
        return res;
    }
};