class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s(nums2.begin(),nums2.end());
        for(auto n:nums1){
            if(s.count(n)){
                return n;
            }
        }
        return -1;
    }
};