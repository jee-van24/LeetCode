class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int>s1,s2;
        vector<int>res;
        int common=0;
        for(int i=0;i<A.size();i++){
            s1.insert(A[i]);
            s2.insert(B[i]);
            if(A[i]==B[i]){
                common++;
                res.push_back(common);
                continue;
            }
            if(s1.count(B[i])){
                common++;
            }
            if(s2.count(A[i])){
                common++;
            }
            res.push_back(common);
        }
        return res;
    }
};