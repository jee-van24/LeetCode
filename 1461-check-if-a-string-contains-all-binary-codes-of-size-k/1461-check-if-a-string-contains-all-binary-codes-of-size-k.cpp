class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>set;
        int l=0;
        int possible=1<<k;
        string curr;
        for(int r=0;r<s.size();r++){
           curr+=s[r];
           while(curr.size()>k){
                curr.erase(0,1);
                l++;
           }
            if(curr.size()==k){
                set.insert(curr);
            }
            if(set.size()==possible)return true;
        }
        return false;
    }
};