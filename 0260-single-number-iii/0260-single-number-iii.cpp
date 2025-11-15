class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr=0;
        for(auto n:nums){
            xorr^=n;
        }
        long long rightmostset=(xorr&(xorr-1))^xorr;
        int b1=0,b2=0;
        for(auto n:nums){
            if(n&rightmostset){
                b1^=n;
            }else{
                b2^=n;
            }
        }
        return {b1,b2};

    }
};