class Solution {
public:
    bool isprime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        bool ans=true;
        int targ = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                targ = nums[i];
            } else {
                targ = nums[i] - nums[i - 1];
            }
            if (targ <= 0) {
                ans=false;
                break;
            }
            int largestprime = 0;
            for (int j = targ-1; j>=2; j--) {
                if (isprime(j)) {
                    largestprime = j;
                    break;
                }
            }
            nums[i] -= largestprime;
        }
        for(auto n:nums){
            cout<<n<<" ";
        }
        return ans;
    }
};