class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int d1=0,d2=0;
        if(start>destination)swap(start,destination);
        for(int i=start;i<destination;i++){
            d1+=distance[i];
        }
        int total=0;
        for(auto num:distance){
            total+=num;
        }
        d2=total-d1;
        return min(d1,d2);
    }
};