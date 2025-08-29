class Solution {
public:
    long long flowerGame(int n, int m) {
        if(n==1&&m==1)return 0;
        long long oddn=0,evenn=0,oddm=0,evenm=0;
        for(int i=1;i<=n;i++){
            if(i%2==1){
                oddn++;
            }else{
                evenn++;
            }
        }
        for(int i=1;i<=m;i++){
            if(i%2==1){
                oddm++;
            }else{
                evenm++;
            }
        }
        return oddn*evenm+oddm*evenn;

    }
};