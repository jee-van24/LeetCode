class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>res;
        
        for(int i=0;i<s.size();i+=k){
            int j=i;
            string temp="";
            while(j<s.size()&&temp.size()!=k){
                temp+=s[j];
                j++;
            }
            res.push_back(temp);  
        }
        string last=res[res.size()-1];
        if(last.size()!=k){
            while(last.size()<k){
                last+=fill;
            }  
        }
        res[res.size()-1]=last;
        return res;
    }
};