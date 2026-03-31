class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<int,vector<char>>map1,map2;
        for(int i=0;i<s1.size();i++){
            if(i%2==0){
                map1[0].push_back(s1[i]);
            }else{
                map1[1].push_back(s1[i]);
            }
        }
        for(int i=0;i<s1.size();i++){
            if(i%2==0){
                map2[0].push_back(s2[i]);
            }else{
                map2[1].push_back(s2[i]);
            }
        }
        auto &v=map1[0];
        sort(v.begin(),v.end());
        auto &x=map1[1];
        sort(x.begin(),x.end());
        auto &y=map2[0];
        sort(y.begin(),y.end());
        auto &z=map2[1];
        sort(z.begin(),z.end());
        if(v==y&&x==z)return true;


        return false;
    }
};