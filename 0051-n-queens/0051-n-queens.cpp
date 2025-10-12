class Solution {
public:
    void dfs(int col,vector<string>&board,vector<vector<string>>&res,vector<bool>&rowused,vector<bool>&upperdiagused,vector<bool>&lowerdiagused,int n){
        if(col==n){
            res.push_back(board);
            return;
        }
        //now place the queen at the curr column in any of the 0 to n-1 rows available 
        for(int row=0;row<n;row++){
            if(rowused[row]==false&&lowerdiagused[row+col]==false&&upperdiagused[n-1+row-col]==false){
                board[row][col]='Q';
                rowused[row]=true;
                lowerdiagused[row+col]=true;
                upperdiagused[n-1+row-col]=true;
                dfs(col+1,board,res,rowused,upperdiagused,lowerdiagused,n);
                //backtrack for the next other possibilities 
                board[row][col]='.';
                rowused[row]=false;
                lowerdiagused[row+col]=false;
                upperdiagused[n-1+row-col]=false;  
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<bool>upperdiag(2*n-1,false),lowerdiag(2*n-1,false),row(n,false);
        dfs(0,board,res,row,upperdiag,lowerdiag,n);
        return res;

    }
};