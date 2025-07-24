class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>map;
        for(auto c:magazine){
            map[c]++;
        }
        for(auto ch:ransomNote){
            if(map[ch]==0){
                return false;
            }
            map[ch]--;
        }
         return true;
    }
};