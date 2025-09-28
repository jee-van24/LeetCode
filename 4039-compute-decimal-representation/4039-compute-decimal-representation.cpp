class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>res;
        string str=to_string(n);
        int digcnt=str.size();
        for(auto ch:str){
            int dig=ch-'0';
            int num=dig*pow(10,(digcnt-1));
            if(num!=0){
                res.push_back(num);
            }
            
            digcnt--;
        }
        for(auto ch:str){
            cout<<ch;
        }
        return res;
    }
};