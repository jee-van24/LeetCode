class Solution {
public:
    double myPow(double x, int n) {
        long long exp=n;
        if(exp<0){
           exp=-1*exp;
        }
        double res=1;
        while(exp!=0){
            if(exp%2==1){
                res*=x;
                exp=exp-1;
            }else{
                 x*=x;
                exp=exp/2;
            }
           
        }
        if(n<0){
            return 1/res;
        }
        return res;
    }
};