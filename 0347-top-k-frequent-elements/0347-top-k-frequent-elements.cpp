class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        priority_queue<pair<int,int>>pq;
        for(auto n:nums){
            map[n]++;
        }
        for(auto &p:map){
            pq.push({p.second,p.first});
        }
        vector<int>res;
        while(k>0){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;

    }
};