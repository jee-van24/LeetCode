class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        char num='\0';
        int idx=-1;
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]<s[i+1]){
                num=s[i];
                idx=i;
                break;
            }
        }
        if(num=='\0'){
            return -1;
        }
        int i=0;
        for(i=s.size()-1;i>idx;i--){
            if(s[i]>num){
                swap(s[i],s[idx]);
                break;
            }
        }
        reverse(s.begin()+idx+1,s.end());
        long long res=0;
        //now build the number , lets not use stoi cause overflow
        for(i=0;i<s.size();i++){
            int digit=s[i]-'0';
            res=res*10+digit;
            if(res>INT_MAX){
                return -1;
            }
        }
        return res;
    }
};