class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0;
        unordered_map<char,int>map;
        int left=0;
        int maxfreq=0;
        for(int right=0;right<s.size();right++){
            map[s[right]]++;
            maxfreq=max(maxfreq,map[s[right]]);
            while((right-left+1)-maxfreq>k){
                map[s[left]]--;
               
                if(map[s[left]]==0){
                    map.erase(s[left]);
                }
                left++;
            }
            res=max(res,right-left+1);
        }
        return res;
    }   
};