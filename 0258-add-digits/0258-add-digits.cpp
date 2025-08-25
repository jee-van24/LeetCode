class Solution {
public:
    int addDigits(int num) {
        int res=num;
        if(num==0||num<10)return num;
        string curr=to_string(num);
        int sum=num;
        while(res>=10){
            curr=to_string(res);
            int sum=0;
            for(auto ch:curr){
                sum+=ch-'0';
            }
            res=sum;
        }
        return res;
    }
};