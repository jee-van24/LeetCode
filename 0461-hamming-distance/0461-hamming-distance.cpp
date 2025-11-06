class Solution {
public:
    void con(int n,string& s){
        if(n==0){
            return;
        }
        con(n/2,s);
        s.push_back((n%2)+'0');
    }
    int hammingDistance(int x, int y) {
        string s1,s2;
        con(x,s1);
        con(y,s2);
        if(s1.size()!=s2.size()){
            if(s1.size()<s2.size()){
                while(s1.size()!=s2.size()){
                    s1.insert(s1.begin()+0,'0');
                }
            }else{
                while(s1.size()!=s2.size()){
                    s2.insert(s2.begin()+0,'0');
                }
            }
        }
        int res=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                res++;
            }
        }
        return res;
    }
};