class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto ch:s){
            if(ch==')'){
                if(st.empty())return false;
                if(st.top()!='(')return false;
                st.pop();
            }else if(ch==']'){
                if(st.empty())return false;
                if(st.top()!='[')return false;
                st.pop();
            }else if(ch=='}'){
                if(st.empty())return false;
                if(st.top()!='{')return false;
                st.pop();
            }else{
                st.push(ch);
            }
        }
        if(st.size())return false;
        return true;
    }
};