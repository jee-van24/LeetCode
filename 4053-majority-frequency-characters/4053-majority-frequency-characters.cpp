class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int>map;
        for(auto ch:s){
            map[ch]++;
        }
        //now we have the frequency of each character
        int maxfreq=0;
        for(auto p:map){
            maxfreq=max(maxfreq,p.second);
        }
        //now we need to get the majority freq
        unordered_map<int,int>freqtable;
        for(auto p:map){
            auto f=p.second;
            freqtable[f]++;
        }
        int majorityfreq=0;
        int majoritycnt=0;
        for(auto pair:freqtable){
            int currfreq=pair.first;
            int currcnt=pair.second;
            if(currcnt>majoritycnt||currcnt==majoritycnt&&currfreq>majorityfreq){
                majorityfreq=currfreq;
                majoritycnt=currcnt;
            }
        }
        string res="";
        for(auto p:map){
            if(p.second==majorityfreq){
                res.push_back(p.first);
            }
        }
    
        return res;
        
    }
};