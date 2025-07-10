class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>check;
        vector<int>res;
        unordered_set<int>seen;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            if(seen.find(curr)!=seen.end()){
                continue;
            }
            int freq=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]==curr)freq++;
            }
            check.push_back({freq,curr});
            seen.insert(curr);
        }
        sort(check.begin(),check.end());
            for(int i=check.size()-1;i>=0;i--){
                if(res.size()>=k)break;
                res.push_back(check[i].second);
            }
            return res;
    }
};