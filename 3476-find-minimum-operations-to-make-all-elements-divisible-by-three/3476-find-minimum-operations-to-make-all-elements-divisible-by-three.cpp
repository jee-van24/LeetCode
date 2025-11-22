class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        for(auto n:nums){
            if(n%3!=0){
                cnt++;
            }
        }
        return cnt;
    }
};