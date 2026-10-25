class Solution {
public:
    int datekey(const string&date){
        int month=stoi(date.substr(0,2));
        int day=stoi(date.substr(3,2));
        return month*100+day;
    }
    int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int countDaysTogether(string arriveAlice, string endAlice, string arriveBob, string endBob) {
        int aStart=datekey(arriveAlice);
        int aEnd=datekey(endAlice);
        int bStart=datekey(arriveBob);
        int bEnd=datekey(endBob);
        int res=0;
        for(int i=1;i<=12;i++){
            for(int day=1;day<=months[i-1];day++){
                int curr=i*100+day;
                if(curr>=aStart&&curr<=aEnd&&curr>=bStart&&curr<=bEnd){
                    res++;
                }
            }
        }
        return res;
        
    }
};