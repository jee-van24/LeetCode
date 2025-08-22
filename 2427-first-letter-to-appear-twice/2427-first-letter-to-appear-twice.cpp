class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int>seen;

        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(seen.find(ch)==seen.end()){
                seen[ch]++;
            }else if(seen[ch]==1){
                return s[i];
            }else{
                continue;
            }
        }
        return 'a';
    }
};