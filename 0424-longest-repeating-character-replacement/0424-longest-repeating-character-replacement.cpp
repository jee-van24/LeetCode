class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0;
        int left=0;
        int maxfreq=0;
        unordered_map<char,int>map;
        for(int right=0;right<s.size();right++){
            map[s[right]]++;
            maxfreq=max(maxfreq,map[s[right]]);
            while(right-left+1-maxfreq>k){
                map[s[left]]--;
                left++;
            }
            res=max(right-left+1,res);
        }
        return res;
    }
};