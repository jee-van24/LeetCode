class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>map;
        for(auto c:ransomNote){
            map[c]++;
        }
        for(auto pair:map){
            char ch=pair.first;
            if(count(magazine.begin(), magazine.end(), ch)!=pair.second){
                if(count(magazine.begin(), magazine.end(), ch)<pair.second){
                    return false;
                }
                
            }
        }
        return true;
    }
};