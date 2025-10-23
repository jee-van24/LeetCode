class Solution {
public:
    bool hasSameDigits(string s) {
        while(true){
            if(s.size()==2){
                break;
            }
            string temp="";
            for(int i=0;i<s.size()-1;i++){
                int n1=s[i]-'0';
                int n2=s[i+1]-'0';
                int num=(n1+n2)%10;
                char ch=num+'0';
                temp.push_back(ch);
            }
            cout<<temp<<endl;
            s=temp;
        }
        if(s[0]==s[1]){
            return true;
        }
        return false;
    }
};