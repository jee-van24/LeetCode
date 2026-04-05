class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols=encodedText.size()/rows;
        vector<vector<char>>grid(rows,vector<char>(cols,'.'));
        for(int i=0;i<encodedText.size();i++){
            int r=i/cols;
            int c=i%cols;
            grid[r][c]=encodedText[i];
        }
        string res;
        for(int i=0;i<grid[0].size();i++){
            if(i==cols-1){
                res.push_back(grid[0][cols-1]);
                break;
            }
            int startc=i;
            for(int j=0;j<grid.size();j++){
                res.push_back(grid[j][startc]);
                startc++;
                if(startc<cols){
                    continue;
                }else{
                    break;
                }
            }
        }
        for(int i=res.size()-1;i>=0;i--){
            if(res[i]==' ')res.pop_back();
            else break;
        }
        return res;
    }
};