class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int>seen;
        vector<int>res;
        for(auto n:nums){
            if(seen.count(n)){
                res.push_back(n);
            }else{
                seen.insert(n);
            }
        }
        return res;
    }
};