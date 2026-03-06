class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res=0;
        int l=0;
        int mask=0;//positions of where set bits are because its unqiue , no two numbers can share a setbit at the same place eg:
        //eg 5 is  101 , 2 is 10 , mask will be 1 1 1 saying bit pos 0 1 2 are occupied
        for(int r=0;r<nums.size();r++){
            while((mask&nums[r])!=0){
                mask=mask^nums[l];
                l++;
            }
            mask|=nums[r];
            res=max(res,r-l+1);
        }
        return res;
    }
};