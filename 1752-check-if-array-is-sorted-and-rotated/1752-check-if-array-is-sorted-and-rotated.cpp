class Solution {
public:
    bool check(vector<int>& nums) {

        bool f1 = false;
        bool f2 = false;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] < nums[i-1] && !f1 && !f2) {

                f1 = true;

            }
            else if(nums[i] < nums[i-1] && f1 && !f2) {

                return false;

            }
            else if(nums[i] > nums[i-1] && f1 && !f2) {

                f2 = true;

            }
            else if(nums[i] < nums[i-1] && f1 && f2) {

                return false;
            }
        }

        if(!f1 && !f2)
            return true;

        if(f1 && nums.back() <= nums[0])
            return true;

        return false;
    }
};