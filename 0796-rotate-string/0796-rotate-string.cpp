class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        s+=s;
        int sz=goal.size();
        int l=0;
        for(int r=0;r<s.size();r++){
            if(r-l+1==sz){
                string str=s.substr(l,sz);
                if(str==goal)return true;
                l++;
            }
        }
        return false;
    }
};