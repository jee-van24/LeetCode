class Solution {
public:
    bool checkOnesSegment(string s) {
        char prev=s[0];
        int first=-1;
        for(int i=1;i<s.size();i++){
            if(prev=='0'&&s[i]=='1'&&first!=-1)return false;
            else if(first==-1)first=0;
            prev=s[i];
        }
        return true;
    }
};