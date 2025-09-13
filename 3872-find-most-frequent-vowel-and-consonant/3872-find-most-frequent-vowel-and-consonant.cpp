class Solution {
public:
    int maxFreqSum(string s) {
        int maxv=0;
        int maxc=0;
        unordered_set<char>set={'a','e','i','o','u'};
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;
        for(auto ch:s){
            if(set.find(ch)!=set.end()){
                map1[ch]++;
                maxv=max(maxv,map1[ch]);
            }else{
                map2[ch]++;
                maxc=max(maxc,map2[ch]);
            }
        }

        return maxv+maxc;
    }
};