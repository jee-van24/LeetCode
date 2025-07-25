class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int sum = 0;
        bool flag = false;
        // if all the numbers are negaive;
        for (auto num : nums) {
            if (num >= 0) {
                flag = true;
                break;
            }
        }

        if (nums.size() == 1)
            return nums[0];
        if (flag) {
            for (auto num : nums) {
                if ((seen.find(num) == seen.end()) && num >= 0) {
                    sum += num;
                    seen.insert(num);
                }
            }
            return sum;
        } else {
           for(auto num:nums){
            if(num<sum&&sum==0){
                sum=num;
            }else{
                sum=max(sum,num);
            }
           }
           return sum;
        }
    }
};