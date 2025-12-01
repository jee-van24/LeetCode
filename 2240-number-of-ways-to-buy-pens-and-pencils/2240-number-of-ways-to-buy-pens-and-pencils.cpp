class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long cnt=0;
        if(total<cost1&&total<cost2)return 1;
        cnt+=total/cost2;
        cnt+=1;//if i buy 0 pens and all the pencils
        for(int i=1;i*cost1<=total;i++){
            int temp=total;
            cnt+=1;
            temp-=i*cost1;
            cnt+=temp/cost2;
        }

    return cnt;
    }
};