class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>map;
        int l=0;
        int n=s.size();
        int lasta=-1,lastb=-1,lastc=-1;
        int res=0;
        for(int r=0;r<s.size();r++){
            if(s[r]=='a'){
                lasta=r;
            }else if(s[r]=='b'){
                lastb=r;
            }else{
                lastc=r;
            }
            if(lasta!=-1&&lastb!=-1&&lastc!=-1){
                res++;
                res+=min({lasta,lastb,lastc});
            }
        }
        return res;
    }
};