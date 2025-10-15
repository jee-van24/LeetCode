class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int>lens;
        int maxk=0;
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
        for(int len:lens){
            maxk=max(maxk,len/2);
        }
        for(int i=1;i<lens.size();i++){
            maxk=max(maxk,min(lens[i],lens[i-1]));
        }
        return maxk;
    }
};