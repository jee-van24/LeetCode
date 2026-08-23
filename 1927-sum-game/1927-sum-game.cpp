class Solution {
public:
    bool sumGame(string num) {
        int Lq=0,Rq=0;
        int lsum=0,rsum=0;
        for(int i=0;i<num.size();i++){
            if(num[i]=='?'){
                if(i<num.size()/2){
                    Lq++;
                }else{
                    Rq++;
                }
            }else{
                if(i<num.size()/2){
                    lsum+=num[i]-'0';
                }else{
                    rsum+=num[i]-'0';
                }
            }
        }
        if(Lq==0&&Rq==0){
            if(lsum==rsum){
                return false;
            }
            return true;
        }
        if((Lq+Rq)%2==1){
            //the total qs are odd , alice will always win 
            return true;
        }
        int extraq=abs(Lq-Rq);
        if(Lq>Rq){
            if(rsum==lsum+9*(extraq/2)){
                return false;
            }else{
                return true;
            }
        }else if(Rq>Lq){
            if(lsum==rsum+9*(extraq/2)){
                return false;
            }else{
                return true;
            }
        }else if(Lq==Rq){
            if(lsum==rsum){
                return false;
            }
            return true;
        }
        return false;
    }
};