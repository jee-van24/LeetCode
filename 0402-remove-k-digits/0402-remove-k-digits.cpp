class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        stack<char> s;
        int i = 0;
        if(num=="100")return "0";
        bool flag = true;
        if (k == num.size())
            return "0";
        while (i < num.size()) {
            while (!s.empty() && s.top() > num[i] && k > 0) {
                s.pop();
                k--;
            }
            s.push(num[i]);
            i++;
        }
        while(k>0){
            s.pop();
            k--;

        }
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        i=0;
        //to check only if zeroes are there 
        bool f=true;
        for(int j=0;j<res.size();j++){
            if(res[j]!='0'){
                f=false;
                break;
            }
        }
        if(f){
            return res;
        }
        while(i<res.size()&&res[i]=='0'){
            i++;
        }
        res=res.substr(i);
        return res;
    }
};