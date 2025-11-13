class Solution {
public:
    int minChanges(string s) {
        int onecnt=0,zerocnt=0;
         for(auto ch:s){
            if(ch=='0'){
                zerocnt++;
            }else{
                onecnt++;
            }
         }
         if(zerocnt==s.size()||onecnt==s.size()){
            return 0;
         }
         else{
            return min(s.length()-zerocnt,s.length()-onecnt);
         }
         return 0;
    }
};