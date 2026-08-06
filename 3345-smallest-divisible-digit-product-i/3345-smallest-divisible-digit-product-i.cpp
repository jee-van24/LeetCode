class Solution {
public:
    int solve(int n){
        int res=1;
        while(n!=0){
            int rem=n%10;
            n/=10;
            res*=rem;
        }
        return res;
    }
    int smallestNumber(int n, int t) {
        while(true){
            int prod=solve(n);
            if(prod%t==0)return n;
            n+=1;
        }
        return 0;

    }
};