class Solution {
public:
    int smallestNumber(int n) {
        int bits = floor(log2(n)) + 1;
        int maxi=(1<<bits)-1;
        int comp1=n&maxi;
        return n|maxi;
    }
};