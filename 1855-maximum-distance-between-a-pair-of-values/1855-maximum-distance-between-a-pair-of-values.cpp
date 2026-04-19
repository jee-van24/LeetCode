class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res=INT_MIN;
        int n=nums1.size(),m=nums2.size();
        int i=0,j=0;
        while(i<n&&j<m){
            while(j<m&&nums1[i]<=nums2[j]){
                res=max(res,j-i);
                j++;
            }
            while(i<n&&j<m&&nums1[i]>nums2[j]){
                i++;
            }
            if(i>j)j=i;
        }
        if(res==INT_MIN)return 0;
        return res;
    }
};