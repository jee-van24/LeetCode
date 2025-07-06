class Solution {
public:
    int maxProduct(int n) {
        string temp=to_string(n);
        sort(temp.rbegin(),temp.rend());
        int d1=temp[0]-'0';
        int d2=temp[1]-'0';
        return d1*d2;
    }
};