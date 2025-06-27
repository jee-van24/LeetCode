class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>map;
        vector<char>used;
        for( int i=0;i<s.size();i++){
            char ch=s[i];
            if(map.find(ch)==map.end()){
                if(find(used.begin(), used.end(), t[i]) == used.end()){
                    map[ch]=t[i];
                    used.push_back(t[i]);
                }else{
                    return false;
                }
                
            }
            
            if(map[ch]!=t[i]){
                return false;
            }
        }
        return true;
    }
};