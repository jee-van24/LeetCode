class Solution {
public:
    vector<int> productQueries(int N, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<int> power;
        
        long long val = 1;
        while (val <= 1e9) {
            power.push_back(val);
            val *= 2;
        }
        
        vector<long long> arr;
        for (int i = power.size() - 1; i >= 0; i--) {
            if (N >= power[i]) {
                arr.push_back(power[i]);
                N -= power[i];
            }
        }
        
        reverse(arr.begin(), arr.end());
        
        vector<int> res;
        for (auto& range : queries) {
            long long temp = 1;
            for (int i = range[0]; i <= range[1]; i++) {
                temp = (temp * arr[i]);
                if(temp>MOD){
                    temp%=MOD;
                }
            }
            res.push_back(temp);
        }
        
        return res;
    }
};
