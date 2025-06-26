class Solution {
public:
    string largestOddNumber(string num) {
        string res="";
        for(int i=num.size()-1;i>=0;i--){
            int digit= num[i]-'0';//subtracting ascii value of '0' to give numeric val
            if(digit%2!=0){
                res=num.substr(0,i+1);
                return res;
            }
        }
        return res;
    }
};