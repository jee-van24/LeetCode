class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        for(int i=0;i<nums1.size();i++){
            int ans=-1;
            for(int j=nums2.size()-1;j>=0;j--){
                if(nums1[i]==nums2[j]){
                    res.push_back(ans);
                    break;
                }
                if(nums2[j]>nums1[i])ans=nums2[j];
            }
        }
        return res;
    }
};