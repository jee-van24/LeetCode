class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char>set={'a','e','i','o','u'};
        int cnt=0;
        for(auto ch:s){
            if(set.find(ch)!=set.end()){
                cnt++;
                return true;
            } 
        }
       return false;
    }
};