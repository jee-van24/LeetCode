class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>map;
        for(auto n:nums){
            map[n]++;
        }
        vector<int>res;
        for(auto &p:map){
            if(p.second==1){
                res.push_back(p.first);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};