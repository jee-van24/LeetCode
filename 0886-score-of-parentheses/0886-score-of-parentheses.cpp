class Solution {
public:
    int count(string &s ,int & start){
        int score=0;
        while(start<s.size()){
            if(s[start]=='('&&s[start+1]==')'){
                score++;
                start+=2;//skip ')'
            }else if(s[start]=='('){
                start++;
                score+=2*count(s,start);
                start++;
            }else{
                break;
            }
        }
        return score;
    }
    int scoreOfParentheses(string s) {
        int i=0;
        int ans=count(s,i);
        return ans;
    }
};