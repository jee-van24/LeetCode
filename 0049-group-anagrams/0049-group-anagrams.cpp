class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         vector<vector<string>>res;
       unordered_map<string,vector<string>>map;
       for(auto str:strs){
            string key=str;
            sort(key.begin(),key.end());
            map[key].push_back(str);
       }
       for(auto &p:map){
        cout<<p.first<<" ";
        for(auto s:p.second){
            cout<<s<<" ";
        }
        cout<<endl;
       }
       for(auto &p:map){
            res.push_back(p.second);
       }
        return res;
    }
};