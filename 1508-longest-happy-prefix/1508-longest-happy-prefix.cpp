class Solution {
public:
    string longestPrefix(string s) {
        string res="";
        int n=s.length();
        vector<int>lps(n,0);
        int len=0,i=1;
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
        int plen=lps[n-1];
        res=s.substr(0,plen);
        return res;
    }
};