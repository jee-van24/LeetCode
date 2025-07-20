class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans=INT_MAX;
        unordered_map<int,int>map;
        for(int i=0;i<cards.size();i++){
            int curr=cards[i];
            if(map.find(curr)==map.end()){
                map[curr]=i;
            }else{
                ans=min(ans,i-map[curr]+1);
                map[curr]=i;
            }
        }
        return(ans==INT_MAX)?-1:ans;
    }
};