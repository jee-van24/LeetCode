class Solution {
public:
    int maximumUniqueSubarray(vector<int>&nums){
        vector<int>seen;
        int res=0;
        for(int right=0;right<nums.size();right++){
            int curr=nums[right];
            if(find(seen.begin(),seen.end(),curr)==seen.end()){
                seen.push_back(curr);
            }else{
                int sum=accumulate(seen.begin(),seen.end(),0);
                res=max(res,sum);
                while(find(seen.begin(),seen.end(),curr)!=seen.end()){
                    seen.erase(seen.begin());
                }
                seen.push_back(curr);

            }
       }
       int finalSum = accumulate(seen.begin(), seen.end(), 0);
       res=max(res,finalSum);
       return res; 
    }
};