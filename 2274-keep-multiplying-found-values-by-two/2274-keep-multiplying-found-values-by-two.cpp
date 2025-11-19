class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>seen(nums.begin(),nums.end());
        int check=original;
        while(true){
            if(seen.find(check)==seen.end()){
                return check;
            }
            check*=2;

        }
        return 0;
    }
};