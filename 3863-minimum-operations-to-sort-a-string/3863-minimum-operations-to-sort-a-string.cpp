class Solution {
public:
    int minOperations(string nums) {
        if(is_sorted(nums.begin(),nums.end())){
            return 0;
        }
        if(nums.size()==2){
            return -1;
        }
        char max_ch=*max_element(nums.begin(),nums.end());
        char min_ch=*min_element(nums.begin(),nums.end());
        char min_mid=*min_element(nums.begin()+1,nums.end()-1);
        char max_mid=*max_element(nums.begin()+1,nums.end()-1);

        if(nums[0]==min_ch||nums[nums.size()-1]==max_ch){
            return 1;
        }else if(nums[0]>max_mid&min_mid>nums[nums.size()-1]){
            return 3;
        }
        return 2;
    }
};