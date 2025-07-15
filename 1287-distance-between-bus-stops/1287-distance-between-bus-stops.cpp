class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int d1=0,d2=0;
        if(start>destination)swap(start,destination);
        for(int i=0;i<destination;i++){
            if(i>=start&&start<destination){
                d1+=distance[i];
            }
        }
        int total=accumulate(distance.begin(),distance.end(),0);
        d2=total-d1;
        return min(d1,d2);
    }
};