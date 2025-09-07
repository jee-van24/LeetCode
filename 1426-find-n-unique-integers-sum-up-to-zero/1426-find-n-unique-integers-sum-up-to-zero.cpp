class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>res;
        int sum=0;
        if(n==1)return {0};
            for(int i=1;i<=n-1;i++){
                res.push_back(i);
                sum+=i;
            }
            res.push_back(-sum);
        
        return res;
    }
};