class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int prev=-1;
        int res=INT_MIN;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1){
                if(prev==-1){
                    //the first occupied
                    prev=i;
                }else{
                   res=max(res,(i-prev)/2);
                   prev=i;
                }
            }
        }
        int firstidx=-1,lastidx=-1;
        //ill try to place it at the extreme 0s
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1){
                if(firstidx==-1){
                    firstidx=i;
                    lastidx=i;
                }else{
                    lastidx=i;
                }
            }
        }
        for(int i=0;i<seats.size();i++){
            if(seats[i]==0){
                int d=firstidx-i;
                res=max(d,res);
                break;
            }
        }
        for(int i=seats.size()-1;i>=0;i--){
            if(seats[i]==0){
                int d=i-lastidx;
                res=max(res,d);
                break;
            }
        }
        return res;
    }
};