class Solution {
public:
    bool check(int n,int idx){
        int s=0;
        while(n!=0){
            int rem=n%10;
            s+=rem;
            n/=10;
        }
        return s==idx;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(check(nums[i],i)){
                return i;
            }
        }
        return -1;
    }
};