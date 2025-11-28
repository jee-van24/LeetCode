class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int>&a,const vector<int>&b){
            return a[0]<b[0];
        });
        for(auto v:points){
            for(auto n:v){
                cout<<n<<" ";
            }
            cout<<"     ";
        }
        auto first=points[0];
        auto end=points[0][1];
        int res=1;//im counting the first one separately
        for(int j=1;j<points.size();j++){
            if(points[j][0]<=end){
                end=min(end,points[j][1]);            
                continue;
            }
            res+=1;
            end=points[j][1];
        }
        return res;
    }
};