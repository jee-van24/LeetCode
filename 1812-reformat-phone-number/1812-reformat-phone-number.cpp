class Solution {
public:
    string reformatNumber(string number) {
        string digits="";
        for(char c:number){
            if(isdigit(c)){
                digits+=c;
            }
        }
        string res="";
        int n=digits.size();
        int i=0;
        for(i=0;n-i>4;i+=3){
            res+=digits.substr(i,3)+"-";
        }
        if(n-i==4){
            res+=digits.substr(i,2)+"-"+digits.substr(i+2,2);
        }else{
            res+=digits.substr(i);
        }
        return res;
    }

};