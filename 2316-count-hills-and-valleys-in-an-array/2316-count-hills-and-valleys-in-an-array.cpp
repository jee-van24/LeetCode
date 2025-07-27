class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int>arr;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(i==0||nums[i]!=nums[i-1]){
                arr.push_back(nums[i]);
            }
        }
        for(int i=1;i<arr.size()-1;i++){
            if((arr[i]>arr[i-1]&&arr[i]>arr[i+1])||arr[i]<arr[i-1]&&arr[i]<arr[i+1]){
                res++;
            }
        }
        return res;
    }
};