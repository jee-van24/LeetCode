class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>map;
        vector<char>used;
        for( int i=0;i<s.size();i++){
            char ch=s[i];
            if(map.find(ch)==map.end()){
                if(find(used.begin(), used.end(), t[i]) != used.end()){
                    return false;
                }
                map[ch]=t[i];
                used.push_back(t[i]);
            }
            
            if(map[ch]!=t[i]){
                return false;
            }
        }
        return true;
    }
};