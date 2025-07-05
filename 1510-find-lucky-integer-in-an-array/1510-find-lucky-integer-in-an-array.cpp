class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        unordered_map<int,int>map;
        for(auto num:arr){
            map[num]++;
        }
        for( auto pair: map){
            if(pair.first==pair.second){
                ans=max(ans,pair.first);
            }
        }
        return ans;
    }
};