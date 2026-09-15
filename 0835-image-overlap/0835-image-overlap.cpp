class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int maxcnt=0;
        int n=img1.size();
        for(int roffset=-n+1;roffset<n;roffset++){
            for(int coffset=-n+1;coffset<n;coffset++){
                int currcnt=0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        int Ridx=i+roffset;
                        int Cidx=j+coffset;
                        if(Ridx<0||Ridx>=n||Cidx<0||Cidx>=n){
                            continue;
                        }
                        if(img1[i][j]+img2[Ridx][Cidx]==2){
                            currcnt++;
                        }
                    }
                    maxcnt=max(maxcnt,currcnt);
                }
            }
        }
        return maxcnt;
    }
};