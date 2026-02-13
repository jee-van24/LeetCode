class Solution {
public:
    int longestBalanced(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int>map;
            unordered_map<int,int>map1;
            for(int j=i;j<s.size();j++){
                int oldfreqcnt=map[s[j]];
                if(oldfreqcnt>0){
                    map1[oldfreqcnt]--;
                    if(map1[oldfreqcnt]==0){
                        map1.erase(oldfreqcnt);
                    }
                }
                map[s[j]]++;
                int newfreqcnt=map[s[j]];
                map1[newfreqcnt]++;
                if(map1.size()==1){
                    res=max(res,j-i+1);
                } 
            }
        }
        return res;
    }
};