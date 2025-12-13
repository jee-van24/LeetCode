class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_set<string>s;
        map<string,vector<string>>map;
        s.insert("electronics");
        s.insert("grocery");
        s.insert("pharmacy");
        s.insert("restaurant");
        vector<string>res;
        for(int i=0;i<code.size();i++){
            auto str=code[i];
            if(str=="")continue;
            cout<<str<<" ";
            bool f=true;
            for(auto ch:str){
                if(!isalnum(ch)){
                    if(ch!='_'){
                        f=false;
                        break;
                    }
                }
            }
            if(!f)continue;
            //basically str is a valid string 
            auto b=businessLine[i];
            if(!s.count(b))continue;
            //basically businees code is also valid
            if(!isActive[i])continue;
            //basically code is valid , buisnessLine is valid and its also active , so its a valid coupon
            
            map[b].push_back(str);

        }
        for(auto p:map){
            auto v=p.second;
            sort(v.begin(),v.end());
            for(auto s:v)res.push_back(s);
        }
        return res;

    }
};