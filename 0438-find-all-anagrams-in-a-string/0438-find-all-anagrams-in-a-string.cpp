class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        unordered_map<char,int>ref,map;
        for(auto c:p)ref[c]++;
        int left=0;
        string temp;
        for(int right=0;right<s.size();right++){
            temp+=s[right];
            map[s[right]]++;
            while(temp.size()>p.size()){
                map[s[left]]--;
                if(map[s[left]]==0){
                    map.erase(s[left]);
                }
                left++;
                temp.erase(0,1);
            }
            if(map==ref){
                res.push_back(left);
            }
        }
        return res;
    }
};