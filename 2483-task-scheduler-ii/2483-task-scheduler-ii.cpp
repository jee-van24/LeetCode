class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long daycnt=1;
        unordered_map<long,long>map;
        for(auto task:tasks){
            if(map.count(task)){
                if(daycnt-(map[task]+1)<space){
                    daycnt=map[task]+1+space;
                }
            }
            map[task]=daycnt;
            daycnt++;
        }
        return daycnt-1;
    }
};