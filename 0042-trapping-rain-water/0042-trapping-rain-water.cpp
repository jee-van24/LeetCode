class Solution {
public:
    int trap(vector<int>& heights) {
        int n=heights.size();
        vector<int>pref(n,0),suff(n,0);
        pref[0]=heights[0];
        suff[n-1]=heights[n-1];
        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1],heights[i]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=max(suff[i+1],heights[i]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(heights[i]<pref[i]&&heights[i]<suff[i]){
                res+=min(pref[i],suff[i])-heights[i];
            }
        }
        return res;
    }
};