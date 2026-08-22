class Solution {
public:
    int minOperations(string s1, string s2) {
        int res=0;
        if(s1.size()==1){
            if(s1[0]==s2[0]){
                return 0;
            }else if(s1[0]=='0'&&s2[0]=='0'){
                return 1;
            }else if(s1[0]=='0'){
                return 1;
            }else{
                return -1;
            }
                
        }
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]){
                continue;
            }else{
                if(s1[i]=='0'&&s2[i]=='1'){
                    s1[i]='1';
                    res++;
                }else if(s1[i]=='1'&&s2[i]=='0'){
                    if(i+1<s1.size()&&s1[i+1]=='1'){
                        res+=1;
                        s1[i+1]='0';
                    }else if(s1[i+1]=='0'){
                        res+=2;
                        s1[i+1]='0';
                    }else if(i-1>=0){
                        res+=2;
                    }
                }
            }
        }
         return res;
    }
};