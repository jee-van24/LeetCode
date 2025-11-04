class Solution {
public:
    long long countSubstrings(string s, char c) {
        int res=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                cnt++;
                res+=cnt;
            }
        }
        return res;
    }
};