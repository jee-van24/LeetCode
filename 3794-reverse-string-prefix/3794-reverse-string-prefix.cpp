class Solution {
public:
    string reversePrefix(string s, int k) {
        string res;
        if(k==s.size()){
            reverse(s.begin(),s.end());
            return s;
        }
        string y=s.substr(0,k);
        reverse(y.begin(),y.end());
        res+=y;
        s=s.substr(k);
        res+=s;
        return res;
    }
};