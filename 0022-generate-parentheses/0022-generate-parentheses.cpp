class Solution {
public:
    vector<string>backtrack(int n,int open,int close,string s){
        vector<string>res;
        vector<string>temp;
        if(open==n&&close==n){
            res.push_back(s);
            return res;
        }
        // always consider two possibilities and try to add ( first
        if(open<n){
            temp=backtrack(n,open+1,close,s+'(');
            res.insert(res.end(),temp.begin(),temp.end());
        }
        if(close<open){
            temp=backtrack(n,open,close+1,s+')');
            res.insert(res.end(),temp.begin(),temp.end());
        }
        return res;

    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        res=backtrack(n,0,0,"");
        return res;

    }
};