class Solution {
public:
    string breakPalindrome(string s) {
        string res=s;
        if(s.size()==1)return "";
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!='a'){
                res[i]='a';
                return res;
            }
        }
        res[s.size()-1]='b';

        return res;
    }
};