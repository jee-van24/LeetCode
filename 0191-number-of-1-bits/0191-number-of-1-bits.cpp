class Solution {
public:
    int hammingWeight(int n) {
            if((n&n-1)==0){
                return 1;
            }else{
                int cnt=0;
                while(n!=0){
                    n=(n&(n-1));
                    cnt++;
                }
                return cnt;
            }
            return 0;
    }
};