class Solution {
public:
    bool isinteger(double x){
        return floor(x)==x;
    }
    bool judgeSquareSum(int c) {
        if(c==0)return true;
        long long i=1;
        for(int i=1;i<=sqrt(c);i++){
            double b=sqrt(c-i*i);
            if(isinteger(b))return true;
        }
        return false;
    }
};