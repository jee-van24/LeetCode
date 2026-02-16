class Solution {
public:
    string conv(int n){
        string res;
        while(n!=0){
            int rem=(n%2)+'0';
            res+=rem;
            n/=2;
        }
        reverse(res.begin(),res.end());
        while(res.size()!=32){
            res.insert(0,1,'0');
        }
        return res;
    }
    int num(string s){
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                continue;
            }
            int temp=1<<(s.size()-i-1);
            res+=temp;
        }
        return res;
    }
    int reverseBits(int n) {
        string s=conv(n);
        cout<<s<<endl;
        reverse(s.begin(),s.end());
        cout<<s;
        int res=num(s);
        return res;
    }
};