class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
               // int j=i+1;
              //  while(nums[j]==nums[i-1]){
                   // j++;
                   continue;
            }

                nums[k]=nums[i];
                k++;
                //i=j+1;
        }
        return k;
    }
};