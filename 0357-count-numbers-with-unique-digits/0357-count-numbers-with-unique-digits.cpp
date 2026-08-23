class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){
            return 1;
        }
        int ans=1;
        int ways=9;
        ans+=ways;
        for(int k=2;k<=n;k++){
            ways *=(11-k);
            ans+=ways;
        }
        return ans;
    }
};