class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int res = 0;
        int i = 0, j = 0;
        while (i < nums.size() && j < nums.size()) {
            if (nums[i] < nums[j]) {
                res++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return res;
    }
};
