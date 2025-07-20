class Solution {
public:
    string removeDigit(string number, char digit) {
        string res="";
        int check=0;
        for(int i=0;i<number.size();i++){
            string temp="";
            if(number[i]==digit){
                temp=number.substr(0,i)+number.substr(i+1);
                res=max(res,temp);
            }

        }
        return res;
    }
};