class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>map;
        string res="";
        for(auto ch : s){
            map[ch]++;
        }
        vector<pair<char,int>>freq(map.begin(),map.end());
        sort(freq.begin(),freq.end(),[](const pair<char,int>&a,const
         pair<char,int>&b){
            return a.second>b.second;
         });
         for(auto pair:freq){
            int count=pair.second;
            while(count!=0){
                res+=pair.first;
                count--;
            }
         }
         return res;

    }
};