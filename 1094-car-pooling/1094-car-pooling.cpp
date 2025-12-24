class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        
        unordered_set<int>idx;
        int total=0;
        for(int i=0;i<trips.size();i++){
            total+=trips[i][0];
            for(int j=0;j<i;j++){
                if(idx.find(j)==idx.end()){
                    if(trips[j][2]<=trips[i][1]){
                        total-=trips[j][0];
                        idx.insert(j);
                    }
                }
            }
            if(total>capacity){
                return false;
            }
        }
        return true;
    }
};