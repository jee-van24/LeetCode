class Solution {
public:
    int minimumDeletions(string s) {
        int res=0;
        int bcnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                bcnt++;
            }else{
                res=min(res+1,bcnt);
            }
        }
        return res;
    }
};