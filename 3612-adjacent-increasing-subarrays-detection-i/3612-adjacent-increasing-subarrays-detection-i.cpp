class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<int>lens;
        if(k==1){
            return true;
        }
        int currlen=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                currlen++;
            }else{
                lens.push_back(currlen);
                currlen=1;
            }
        }
        lens.push_back(currlen);
        for(auto len:lens){
            cout<<len<<" ";
        }
        if(lens.size()==1&&lens[0]>=2*k){
            return true;
        }
        for(int i=0;i<lens.size()-1;i++){
            if(lens[i]>=2*k||lens[i]>=k&&lens[i+1]>=k){
                return true;
            }
        }
        if(!lens.empty()&&lens[lens.size()-1]>=2*k){
            return true;
        }
        return false;
    }
};