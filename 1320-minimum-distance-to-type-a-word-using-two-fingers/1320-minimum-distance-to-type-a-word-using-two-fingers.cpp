class Solution {
public:
    int getdist(int a,int b){
        //the first finger has not yet begun typing yet
        if(a==-1)return 0;
        int x1=a/6,y1=a%6;
        int x2=b/6,y2=b%6;
        return abs(x1-x2)+abs(y1-y2);
    }
    int minimumDistance(string word) {
        int n=word.size();
        vector<vector<int>>dp(n,vector<int>(26,INT_MAX));
        //dp[i][j] means the cost to type till iTH idx where the other finger is at jth idx
        for(int i=0;i<26;i++){
            dp[0][i]=0;//typing the first letter is free and the second finger can be assumed to be anywhere
        }
        for(int i=1;i<word.size();i++){
            int curr=word[i]-'A';
            int prev=word[i-1]-'A';
            //i have to type curr, i would have just typed prev
            //either i can use the same finger which i used to type prev to type the curr , or the other finger to type curr 



            //same finger 
            for(int j=0;j<26;j++){
                if(dp[i-1][j]==INT_MAX)continue;
                dp[i][j]=min(dp[i][j],dp[i-1][j]+getdist(prev,curr));
            //other finger
                dp[i][prev]=min(dp[i][prev],dp[i-1][j]+getdist(j,curr));
            }
        }
        int res=INT_MAX;
        for(int j=0;j<26;j++){
            res=min(res,dp[n-1][j]);
        }
        return res;
    }
};