class Solution {
public:
    string removeDuplicates(string s, int k) {
        while(true){
            bool f=false;
            int x=1;
            for(int i=1;i<s.size();i++){
                if(s[i]==s[i-1]){
                    x++;
                    if(x==k){
                        s.erase(i-k+1,k);
                        f=true;
                        break;
                    }
                }else{
                    x=1;
                }
            }
            if(!f)break;
        }
        return s;
    }
};