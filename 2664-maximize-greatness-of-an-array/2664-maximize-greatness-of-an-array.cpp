class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int res = 0;
        vector<int> temp(nums.begin(), nums.end());
        sort(nums.begin(), nums.end()); 
        sort(temp.begin(), temp.end()); 
        int i = 0, j = 0;
        
        while (i < nums.size() && j < temp.size()) {
            if (temp[j] > nums[i]) { 
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
