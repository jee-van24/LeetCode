class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res;
        if(9*num<sum)return res;
        while(res.size()!=num){
            for(char ch='9';ch>='0';ch--){
                if((ch-'0')<=sum){
                    res.push_back(ch);
                    sum-=(ch-'0');
                    break;
                }
            }
        }
        return res;
    }
};