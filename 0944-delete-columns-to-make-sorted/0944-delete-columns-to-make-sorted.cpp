class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res=0;
        unordered_set<int>s;
        for(int i=0;i<strs[0].size();i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j-1][i]>strs[j][i]){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};