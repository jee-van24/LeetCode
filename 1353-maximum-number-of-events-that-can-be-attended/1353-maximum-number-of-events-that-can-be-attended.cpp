class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>minheap;
        int res=0;
        int i=0;
        int n=events.size();
        int lastday=0;
        for(auto v:events){
            lastday=max(lastday,v[1]);
        }
        for(int day=1;day<=lastday;day++){
            //add all events starting today
            while(i<n&&events[i][0]==day){
                minheap.push(events[i][1]);
                i++;
            }
            //delete the ones where their end date is already expired 
            while(!minheap.empty()&&minheap.top()<day){
                minheap.pop();
            }
            if(!minheap.empty()){
                res++;
                minheap.pop();
            }
        }
        return res;
    }
};