class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long curr=1;
        if(n<=0)return false;
        while(curr<=n){
            if(curr==n)return true;
            curr*=2;
        }
        return false;
    }
};