class Solution {
public:
    string tostr(int n){

        string res;
        while(n!=0){
            res.push_back((n%2)+'0');
            n/=2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    int bitwiseComplement(int n) {
        string s;
        int res=0;
        s=tostr(n);
        if(n==0)return 1;
        cout<<s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                res+=1<<(s.size()-i-1);
            }
        }
        return res;
    }
};