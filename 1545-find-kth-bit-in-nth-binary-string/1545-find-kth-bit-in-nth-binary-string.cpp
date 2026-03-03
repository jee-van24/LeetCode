class Solution {
public:
    char findKthBit(int n, int k) {
        string init="0", inv="1";
        string s;
        for(int i=1;i<=n;i++){
            s=init+"1";
            reverse(inv.begin(),inv.end());
            s+=inv;
            init=s;
            inv.clear();
            for(auto ch:s){
                if(ch=='0'){
                    inv+='1';
                }else{
                    inv+='0';
                }
            }
        }
        return s[k-1];
    }
};