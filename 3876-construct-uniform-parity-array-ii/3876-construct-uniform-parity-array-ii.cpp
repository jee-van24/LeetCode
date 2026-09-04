class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minodd=INT_MAX;
        for(auto n:nums1){
            if(n%2==1){
                minodd=min(n,minodd);
            }
        }
        if(minodd==INT_MIN){
            //all even
            return true;
        }
        bool f1=true;
        //gonna try to make all even 
        for(auto n: nums1){
            if(n%2==1){
                if(n-minodd<1){
                    f1=false;
                    break;
                }
            }
        }
        bool f2=true;
        //gonna try to make all odd 
        for(auto n:nums1){
            if(n%2==0){
                if(n-minodd<1){
                    f2=false;
                    break;
                }
            }
        }
        return f1||f2;
    }
};