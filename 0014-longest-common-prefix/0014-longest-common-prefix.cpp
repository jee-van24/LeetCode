class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string pref=s[0];
        int i=1;
        while(i<s.size()){
            string curr=s[i];
            while(curr.size()<pref.size()||pref!=curr.substr(0,pref.size())){
                pref.pop_back();
                if(pref.size()==0){
                    return "";
                }
            }
            i++;
        }
        return pref;
        
    }
};