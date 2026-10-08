class Solution {
public:
    void dfs(int idx , string& curr, string&s, int &res,int balance,int temp,unordered_set<string>&st){
        if(temp>res){
            return;
        }
        if(balance<0){
            return;
        }
        if(idx==s.size()){
            if(balance==0){
                if(temp<res){
                    st.clear();
                    res=temp;
                }
                st.insert(curr);
            }
            return;
        }
        char ch=s[idx];
        if(isalpha(ch)){
            curr.push_back(ch);
            dfs(idx+1,curr,s,res,balance,temp,st);
            curr.pop_back();
        }else{
            //its a ( or )
            curr.push_back(ch);
            if(ch=='('){
                dfs(idx+1,curr,s,res,balance+1,temp,st);
            }else{
                dfs(idx+1,curr,s,res,balance-1,temp,st);
            }
            curr.pop_back();
            dfs(idx+1,curr,s,res,balance,temp+1,st);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        string curr;
        unordered_set<string>st;
        int res=INT_MAX;
        dfs(0,curr,s,res,0,0,st);
        return vector<string>(st.begin(),st.end());
    }
};