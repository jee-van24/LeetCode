class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int>unique(n,0);
        unordered_map<char,vector<int>>map;
        for(int i=0;i<s.size();i++){
            if(!map.count(s[i])){
                map[s[i]].push_back(i);
            }else if(map[s[i]].size()==1){
                map[s[i]].push_back(i);
            }else{
                map[s[i]].back()=i;
            }
        }
        for(auto &p:map){
            cout<<p.first<<endl;
            for(auto n:p.second){
                cout<<n<<" ";
            }
            cout<<endl;
        }
        int res=0;
        for(auto &p:map){
            char ch= p.first;
            auto v=p.second;
            if(v.size()==2){
                int st=v[0];
                int e=v[1];
                unordered_set<char>seen;
                for(int i=st+1;i<e;i++){
                    seen.insert(s[i]);
                }
                res+=seen.size();
            }
        }
        return res;
    }
};