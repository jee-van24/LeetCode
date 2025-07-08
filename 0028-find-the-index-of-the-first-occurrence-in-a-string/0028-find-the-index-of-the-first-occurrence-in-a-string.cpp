class Solution {
public:
    int strStr(string haystack, string needle) {
        int occur=-1;
        int i=0;
        string curr="";
        while(i<haystack.size()){
            int j=0;
            while(haystack[i+j]==needle[j]&&j<needle.size()){
                curr+=haystack[i+j];
                j++;
            }
            if(curr==needle){
                occur=i;
                return occur;
            }
            curr.clear();
            i++;
        }
        return occur;
    }
};