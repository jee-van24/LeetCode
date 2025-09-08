class Solution {
public:
    bool checkzero(int a, int b){
        string s1=to_string(a);
        string s2=to_string(b);
        for(auto ch:s1){
            if(ch=='0'){
                return false;
            }
        }
        for(auto ch:s2){
            if(ch=='0'){
                return false;
            }
        }
        return true;

    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>res;
        for(int i=1;i<=n/2;i++){
            int j=n-i;
            bool check=checkzero(i,j);
            if(check){
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
        return res;
    }
};