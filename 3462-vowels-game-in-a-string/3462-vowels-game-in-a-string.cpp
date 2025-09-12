class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_map<char,int>map;
        unordered_set<char>set={'a','e','i','o','u'};
        int cnt=0;
        for(auto ch:s){
            if(set.find(ch)!=set.end()){
                map[ch]++;
                cnt++;
            } 
        }
        if(cnt==0)return false;
        cout<<cnt;
        for(auto &p:map){
            if(p.second%2==1){
                return true;
            }
        }
        if(cnt%2==0){
            return true;
        }
        return true;
    }
};