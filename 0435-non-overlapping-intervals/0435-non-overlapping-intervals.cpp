class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int res=0;
        for(auto p:intervals){
            for(auto x:p){
                cout<<x<<" ";
            }
            cout<<"     ";
        }
        auto prev=intervals[0];
        for(int i=1;i<intervals.size();i++){
            auto curr=intervals[i];
            if(prev[0]==curr[0]){
                res++;
                continue;
            }
            if(prev[1]>curr[0]){
                res++;
                if(prev[1]>curr[1]){
                    prev=curr;
                }
            }else{
                prev=curr;
            }
        }

        return res;
      
    }
};