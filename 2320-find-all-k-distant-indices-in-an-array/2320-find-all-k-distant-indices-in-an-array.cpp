class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        unordered_set<int>visited;
        int n=nums.size();
        for (int j=0;j<nums.size();j++) {
            if (nums[j]==key) {
                for (int i=max(0,j-k);i<=min(n-1,j+k);
                     i++) {
                    visited.insert(i);
                }
            }
        }
        vector<int>res(visited.begin(),visited.end());
        sort(res.begin(), res.end());
        return res;
    }
};