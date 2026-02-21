class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        unordered_map<char,int>map;
        int res=0;
        for(int right=0;right<s.size();right++){
            map[s[right]]++;
            while(map[s[right]]>1){
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