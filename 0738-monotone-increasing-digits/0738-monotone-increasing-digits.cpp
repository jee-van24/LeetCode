class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str=to_string(n);
        while(true){
            bool flag=true;
            int idx=-1;
            for(int i=str.size()-1;i>0;i--){
                if(str[i]<str[i-1]){
                    //mark the idx and reduce the i-1th dig by 1
                    idx=i;
                    str[i-1]--;
                    flag=false;
                    break;
                }
            }
            if(flag){
                break;
            }
            //change all the digits to 9 
            for(int i=idx;i<str.size();i++){
                str[i]='9';
            }
        }
        return stoi(str);
    }
};