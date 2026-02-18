class Solution {
public:
    string str(int n){
        string res;
        while(n!=0){
            char rem=(n%2)+'0';
            res.push_back(rem);
            n/=2;
        }
        return res;
    }
    bool hasAlternatingBits(int n) {
        string res=str(n);
        for(int i=1;i<res.size();i++){
            if(res[i]==res[i-1]){
                return false;
            }
        }
        return true;
    }
};