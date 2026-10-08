class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>res(seq.size());
        int depth=0;
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                depth++;
                res[i]=(depth%2==0)?0:1;
            }else{
                res[i]=(depth%2==0)?0:1;
                depth--;
            }
        }
        return res;

    }
};