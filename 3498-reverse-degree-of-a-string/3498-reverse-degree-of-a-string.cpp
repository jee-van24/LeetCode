class Solution {
public:
    int reverseDegree(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            int sum=(i+1)*(26-(s[i]-'a'));
            cout<<sum<<" ";
            res+=sum;
        }
        return res;
    }
};