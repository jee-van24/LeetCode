class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;//mo swap required
        vector<int>idx;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]){
                continue;
            }else{
                idx.push_back(i);
            }
            if(idx.size()>2)return false;
        }
        if(idx.size()!=2)return false;
        //either swap those idx in s1 or s2
        int i=idx[0],j=idx[1];
        swap(s1[i],s1[j]);
        if(s1==s2){
            return true;
        }
        return false;
    }
};