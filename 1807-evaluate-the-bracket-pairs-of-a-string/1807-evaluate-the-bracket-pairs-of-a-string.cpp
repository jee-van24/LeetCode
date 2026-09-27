class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>map;
        for(auto v:knowledge){
            auto key=v[0];
            auto val=v[1];
            map[key]=val;

        }
        string res;
        string key;
        int open=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
                continue;
            }
            else if(s[i]==')'){
                //the key string will have the key stored, check if it exists in the map
                if(map.count(key)){
                    res+=map[key];
                }else{
                    res+='?';
                }
                open--;
                cout<<key<<endl;
                key.clear();
                continue;
            }
            if(islower(s[i])&&open!=0){
                key+=s[i];
            }else if(islower(s[i])){
                res+=s[i];
            }
        }
        return res;
    }
};