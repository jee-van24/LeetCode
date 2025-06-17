class Solution {
public:
    int climbStairs(int n) {
        int count=0;
        if(n<=3){
            return n;
        }
       int prev2=2;
       int prev1=3;
       for(int i=3;i<n;i++){
        count=prev1+prev2;
        prev2=prev1;
        prev1=count;

       }
       return count;
    }
};