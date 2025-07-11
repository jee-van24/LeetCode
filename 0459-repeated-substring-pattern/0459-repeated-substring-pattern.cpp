class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        vector<int>lps(n,0);
        int i=1;
        int len=0;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        int lastlps=lps[n-1];
        int unitlen=n-lastlps;
        if(lastlps>0&&n%unitlen==0)return true;
        return false;
    }
};