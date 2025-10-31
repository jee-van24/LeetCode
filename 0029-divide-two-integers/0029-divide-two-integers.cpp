class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)return 1;
        if(divisor==1)return dividend;
        if(dividend==INT_MIN&&divisor==-1)return INT_MAX;
      
        bool sign=true;
        if(dividend>=0&&divisor<0)sign=false;
        else if(dividend<0&&divisor>0)sign=false;

        long long n=abs((long long)dividend);
        long long d=abs((long long)divisor);
        int ans=0;
        while(d<=n){
            int pow=0;
            while((d<<(pow+1))<=n){
                pow++;
            }
            ans+=1<<pow;
            n-=d*(1<<pow);
        }
        if(ans>INT_MAX&&sign)return INT_MAX;
        else if(ans>INT_MAX&&!sign)return INT_MIN;

        return (sign==true)?ans:-1*ans;

    }
};