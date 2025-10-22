class Solution {
public:
    double helper(double res,double base, long long  exp){
        if(exp==0){
            return res;
        }
        if(exp%2==1){
            return helper(res*base,base,exp-1);
        }else{
            return helper(res,base*base,exp/2);
        }
    }
    double myPow(double x, int n) {
        long long exp=n;
        double res=1;
        exp=abs(exp);
        double ans=helper(1,x,exp);
        return n>0?ans:1/ans;
    }
};