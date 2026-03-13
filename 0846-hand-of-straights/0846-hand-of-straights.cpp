class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(begin(hand),end(hand));
        map<int,int>map;
        if(hand.size()%groupSize!=0)return false;
        for(auto n:hand)map[n]++;
        while(true){
            if(map.empty())break;
            int prev=map.begin()->first;
            vector<int>temp;
            temp.push_back(prev);
            for(auto &p:map){
                if(temp.size()==groupSize)break;
                if(p.first==prev+1){
                    temp.push_back(p.first);
                    prev+=1;
                }
            }
            if(temp.size()!=groupSize)return false;
            for(int i=0;i<temp.size();i++){
                map[temp[i]]--;
                if(map[temp[i]]==0){
                    map.erase(temp[i]);
                }
            }
        }
        return true;
    }
};