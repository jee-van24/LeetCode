class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string curr="";
        int left=0;
        for(int right=0;right<s2.size();right++){
            curr+=s2[right];
            if(curr.size()>s1.size()){
                while(curr.size()>s1.size()){
                    curr.erase(curr.begin());
                }
            }if(curr.size()==s1.size()){
                bool flag=true;
                unordered_map<char,int>map;
                for(auto ch:s1){
                    map[ch]++;
                }
                for(auto c:curr){
                    map[c]--;
                    if(map[c]<0){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    return true;
                }
            }
        }
        return false;
    }
};