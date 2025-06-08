class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        result = nums1;

        sort(result.begin(), result.end());  

        int n = result.size();
        double ans = 0.0;

        if (n % 2 != 0) {
            ans = result[n / 2];
        } else {
            ans = (result[n / 2] + result[(n / 2) - 1]) / 2.0;
        }

        return ans;
    }
};
