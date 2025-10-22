class Solution {
public:
    void dfs(int open , int close, string& curr,int n, vector<string>&res){
        if(open==n &&close==n){
            //base case achieved
            res.push_back(curr);
            return;
        }
        //always try to fill ( first if possible 
        if(open<n){
            curr.push_back('(');
            dfs(open+1,close,curr,n,res);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            dfs(open,close+1,curr,n,res);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string>res;
        dfs(0,0,s,n,res);
        return res;
    }
};