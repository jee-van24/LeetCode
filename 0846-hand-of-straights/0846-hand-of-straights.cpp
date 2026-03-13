class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(begin(hand),end(hand));
        unordered_set<int>s;
        if(hand.size()%groupSize!=0)return false;
        for(int i=0;i<hand.size();i++){
            //see if the current idx can be a starting point
            if(!s.count(i)){
                s.insert(i);
                int cnt=1;
                int curr=hand[i];
                int j=i+1;
                while(j<hand.size()&&cnt!=groupSize){
                    if(!s.count(j)&&hand[j]==curr+1){
                        s.insert(j);
                        curr=hand[j];
                        cnt++;
                    }
                    j++;
                }
                if(cnt!=groupSize)return false;
            }
        }
        return true;
    }
};