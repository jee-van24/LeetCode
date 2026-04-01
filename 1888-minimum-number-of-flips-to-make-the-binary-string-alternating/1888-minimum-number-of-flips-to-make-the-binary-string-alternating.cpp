class Solution {
public:
    int minFlips(string s) {
        int res=INT_MAX;
        int n=s.length();
        s+=s;
        string s1,s2;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                s1.push_back('0');
            }else{
                s1.push_back('1');
            }
        }
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                s2.push_back('1');
            }else{
                s2.push_back('0');
            }
        }
        int flip1=0;
        int flip2=0;
        int l=0;

        for(int r=0;r<s.size();r++){
            if(s1[r]!=s[r]){
                flip1++;
            }
            if(s2[r]!=s[r]){
                flip2++;
            }
            if(r-l+1>n){
                if(s[l]!=s1[l]){
                    flip1--;
                }
                if(s[l]!=s2[l]){
                    flip2--;
                }
                l++;
            }
            if(r-l+1==n){
                res=min({res,flip1,flip2});
            }
        }
        return res;
    }
};