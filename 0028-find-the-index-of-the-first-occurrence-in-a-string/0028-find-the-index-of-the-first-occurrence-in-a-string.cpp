class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        int i=1,len=0;
        vector<int>lps(n,0);
        while(i<n){
            if(needle[i]==needle[len]){
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
        i=0;
        int j=0;
        while(i<haystack.size()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==n){
                return i-j;
            }else if(i<haystack.size()&&haystack[i]!=needle[j]){
                if(j!=0){
                    j=lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return -1;
    }
};