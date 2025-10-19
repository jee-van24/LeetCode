class Solution {
public:
    bool rowused[9][10]{}, colused[9][10]{}, subgridused[9][10]{};

    bool check(int row,int col,vector<vector<char>>&grid,char num){
        // i need to check if this currnum can be placed at rowth and colth cell and the subgrid as well 
        int nnum = num - '0';
        int subgrididx=(row/3)*3 + col/3;
        if(!rowused[row][nnum] && !colused[col][nnum] && !subgridused[subgrididx][nnum]){
             return true;
        }
        return false;
    }

    bool dfs(int row,int col,vector<vector<char>>&board,int n){
        if(row==n){
            return true;
        }
        // i gotta check for edge cases boundary checks
        if(col==n){
            return dfs(row+1,0,board,n);
        }
        //need to check if the current cell is filled or unfilled 
        if(board[row][col]!='.'){
            return dfs(row,col+1,board,n);
        }else{
            // try to fill 1 to 9 inside the cell
            for(int i=1;i<=9;i++){
                char ch=i+'0';
                if(check(row,col,board,ch)){
                    int subgrididx=(row/3)*3 + col/3;
                    int nnum = ch - '0';

                    // mark the number as used
                    rowused[row][nnum] = true;
                    colused[col][nnum] = true;
                    subgridused[subgrididx][nnum] = true;
                    board[row][col] = ch;

                    if(dfs(row,col+1,board,n)){
                        return true;
                    }

                    // backtrack
                    rowused[row][nnum] = false;
                    colused[col][nnum] = false;
                    subgridused[subgrididx][nnum] = false;
                    board[row][col] = '.';
                }
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();

        // initialize used arrays from the initial board
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                    int nnum = board[i][j] - '0';
                    int subgrididx = (i/3)*3 + j/3;
                    rowused[i][nnum] = true;
                    colused[j][nnum] = true;
                    subgridused[subgrididx][nnum] = true;
                }
            }
        }

        dfs(0,0,board,n);
    }
};
