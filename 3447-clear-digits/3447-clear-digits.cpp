class Solution {
public:
    string clearDigits(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            if(!res.empty()&&isdigit(s[i])){
                res.pop_back();
            }else{
                res+=s[i];
            }
        }
        return res;
    }
};