class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size(),n=boxGrid[0].size();
        vector<vector<char>>res(n,vector<char>(m,'-'));
        for(int i=0;i<m;i++){
            //iterate each row
            int gapcnt=0,stonecnt=0;
            for(int j=0;j<n;j++){
                if(boxGrid[i][j]=='#'){
                    stonecnt++;
                }else if(boxGrid[i][j]=='.'){
                    gapcnt++;
                }else{
                    //we encountered a obstacle, time to fill the matrix from the start to this obstacle , will be easy because we kept track for stonecnt and gapcnt           
                    int boundary=j-1;
                    //build from start to j-1;
                    for(int k=0;k<stonecnt;k++){
                        boxGrid[i][boundary--]='#';
                    }
                    for(int k=0;k<gapcnt;k++){
                        boxGrid[i][boundary--]='.';
                    }
                    //reset gapcnt and stone cnt for the next segment
                    gapcnt=0;
                    stonecnt=0;
                }
            }
            //filling the last segment in case there are stones and gaps left
            int boundary=n-1;
            for(int k=0;k<stonecnt;k++){
                boxGrid[i][boundary--]='#';
            }
            for(int k=0;k<gapcnt;k++){
                boxGrid[i][boundary--]='.';
            }
        }
        //rotate the matrix now 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[j][m-i-1]=boxGrid[i][j];
            }
        }
        return res;
        

    }
};