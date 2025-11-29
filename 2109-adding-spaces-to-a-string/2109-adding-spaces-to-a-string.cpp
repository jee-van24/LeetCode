class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        unordered_set<int>idx(spaces.begin(),spaces.end());
        int n=s.size()+spaces.size();
        string res;
        cout<<res;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(idx.find(i)!=idx.end()){
                res.push_back(' ');
                res.push_back(s[j]);
                j++;
            }else{
                res.push_back(s[j]);
                j++;
            }
        }
           
        return res;
    }
};