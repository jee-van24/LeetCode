class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        int l=0;
        unordered_map<char,int>map;
        for(auto ch:t){
            map[ch]++;
        }
        int sidx=-1;
        int minlen=INT_MAX;
        int cnt=0;
        for(int r=0;r<s.size();r++){
            if(map.count(s[r])&&map[s[r]]>0){
                cnt++;
            }
            map[s[r]]--;
            while(cnt==t.size()){
                int currlen=r-l+1;
                if(currlen<minlen){
                    sidx=l;
                    minlen=currlen;
                }
                if(map.count(s[l])){
                    map[s[l]]++;
                    if(map[s[l]]>0){
                         cnt--;
                    }    
                }
                l++;
            }
        }
        if(sidx!=-1)res=s.substr(sidx,minlen);
        return res;
    }
};