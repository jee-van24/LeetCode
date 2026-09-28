class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        st.push("");
        for(auto c:s){
            if(c=='('){
                st.push("");

            }else if(c==')'){
                string curr=st.top();
                st.pop();
                reverse(curr.begin(),curr.end());
                st.top()+=curr;
            }else{
                st.top()+=c;
            }
        }
        return st.top();
    }
};