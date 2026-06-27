class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        restrictions.push_back({n,n-1});
        sort(restrictions.begin(),restrictions.end());

        //correct the restrictions of the building from both left to right and right to left
        for(int i=1;i<restrictions.size();i++){
            int prevB=restrictions[i-1][0];
            int currB=restrictions[i][0];
            int dist=abs(currB-prevB);
            int prevlim=restrictions[i-1][1];
            restrictions[i][1]=min(restrictions[i][1],prevlim+dist);
        }
        for(int i=restrictions.size()-2;i>=0;i--){
            int prevB=restrictions[i+1][0];
            int currB=restrictions[i][0];
            int dist=abs(currB-prevB);
            int prevlim=restrictions[i+1][1];
            restrictions[i][1]=min(restrictions[i][1],prevlim+dist);
        }
        int res=0;
        for(int i=1;i<restrictions.size();i++){
            int prevB=restrictions[i-1][0];
            int currB=restrictions[i][0];
            int prevHeight=restrictions[i-1][1];
            int currHeight=restrictions[i][1];
            int dist=abs(currB-prevB);
            int extraDistJustInCaseToMakeSymmetric=abs(prevHeight-currHeight);
            int peak=max(prevHeight,currHeight)+(dist-extraDistJustInCaseToMakeSymmetric)/2;
            res=max(res,peak);
        }
        return res;
    }
};