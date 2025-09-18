class Solution {
public:
    int helper(string& s,int i,int res,int sign){
        if(i>=s.size()||!isdigit(s[i])){
            return res*sign;
        }
        int dig=s[i]-'0';
        if(res>(INT_MAX-dig)/10){
            return sign==1?INT_MAX:INT_MIN;
        }
        return helper(s,i+1,res*10+dig,sign);
    }
    int myAtoi(string s) {
        int i=0;
        while(i<s.size()&&s[i]==' '){
            i++;
        }
        int res=0;
        int sign=1;
        if(i<s.size()&&(s[i]=='+'||s[i]=='-')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        
        return helper(s,i,0,sign);
    }
};