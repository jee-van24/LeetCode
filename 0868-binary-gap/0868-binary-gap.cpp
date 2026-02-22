class Solution {
public:
    string bin(int n){
        string res;
        while(n!=0){
            char rem=n%2+'0';
            res.push_back(rem);
            n/=2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    int binaryGap(int n) {
        string str=bin(n);
        int prev=-1;
        int res=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='1'&&prev==-1){
                prev=i;
            }else if(str[i]=='1'){
                res=max(res,i-prev);
                prev=i;
            }
        }
        if(res==-1){
            return 0;
        }
        return res;
    }
};