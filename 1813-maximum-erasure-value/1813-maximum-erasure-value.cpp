class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left=0,right=0;
        int curr_sum=0,res=0;
        unordered_set<int>seen;
        for(int right=0;right<nums.size();right++){
            int curr=nums[right];
            if(seen.find(curr)==seen.end()){
                curr_sum+=nums[right];
                res=max(curr_sum,res);
                seen.insert(curr);
            }else{
                //keep shrinking from left
              while(seen.find(curr)!=seen.end()){
                curr_sum-=nums[left];
                seen.erase(nums[left]);
                left++;
              }
              curr_sum+=curr;
              seen.insert(curr);
              res=max(res,curr_sum);
            }
        }
        return res;
            
    }
};