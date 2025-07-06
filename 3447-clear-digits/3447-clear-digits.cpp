class Solution {
public:
    string clearDigits(string s) {
        string res=s;
        for(int i=0;i<res.size();i++){
            if(i>0&&isdigit(res[i])){
                res.erase(i-1,2); 
                i-=2;  
            }
        }
        return res;
    }
};