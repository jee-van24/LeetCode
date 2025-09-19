class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int>temp;
        unordered_set<int>set(nums.begin(),nums.end());
        vector<int>res;
        for(auto num:set){
            temp.push_back(num);
        }
        sort(temp.begin(),temp.end(),greater<int>());
        if(temp.size()<k)return temp;
        for(int i=0;i<k;i++){
            res.push_back(temp[i]);
        }
        return res;



    }
};