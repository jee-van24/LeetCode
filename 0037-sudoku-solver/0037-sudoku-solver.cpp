class Solution {
public:
    bool dfs(int row,int col, vector<vector<char>>&board){
        if(row==board.size()){
            return true;
        }
        //to move to the next cell if col has reached the end 
        if(col==board.size()){
            return dfs(row+1,0,board);
        }
        //need to check if the current cell is prefilled or not 
        if(board[row][col]!='.'){
            return dfs(row,col+1,board);
        }else{
            //its a empty cell , need to fill it checking from 1 to 9 
            for(char ch='1';ch<='9';ch++){
                if(canplace(row,col,ch,board)){
                    board[row][col]=ch;
                    if(dfs(row,col+1,board)){
                        return true;
                    }else{
                        board[row][col]='.';//backtrack for other possibilities 
                    }
                }
            }
            return false;
        }

    }
    bool canplace(int row,int col,char num,vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            //need to check if its there in curr row or col or current subgrid 
            if(board[row][i]==num)return false;
            if(board[i][col]==num)return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==num)return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(0,0,board);
    }
};