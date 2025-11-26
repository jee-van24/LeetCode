class Solution {
public:
    int distanceTraveled(int maintank, int additionalTank) {
        int res=0;
        int cnt=0;
        while(true){
            if(maintank<5){
                res+=maintank*10;
                break;
            }else{
                maintank-=5;
                res+=50;
                if(additionalTank){
                    maintank++;
                    additionalTank--;
                }
            }
           
        }
        return res;
    }
};