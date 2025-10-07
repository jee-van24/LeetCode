class Solution {
public:
    bool dfs(int idx, string& s,vector<vector<char>>&board,int r, int c){
        if(idx==s.size()){
            return true;
        }
        if(r<0||c<0||r>=board.size()||c>=board[0].size()||board[r][c]!=s[idx]){
            return false;
        }
        char ch=board[r][c];
        board[r][c]='#';// used for the current call
        bool found=dfs(idx+1,s,board,r+1,c)||dfs(idx+1,s,board,r-1,c)||dfs(idx+1,s,board,r,c-1)||dfs(idx+1,s,board,r,c+1);
        board[r][c]=ch;
        return found;
        

    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(0,word,board,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
};