class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int>seen;
        vector<int>res;
        for(int n:nums){
            if(seen.count(n))
            { res.push_back(n);
            }else{
                seen.insert(n);
            }
        }
        return res;
    }
};