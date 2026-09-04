class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //to make all numbers odd , we need to have atleast one odd number , then every even number can we turned to odd using the second operation 
        //to make all numbers even , i.e odds->even , we must have atleast two odd numbers  , because odd - odd is even
        int odd=0;
        for(auto n:nums1){
            if(n%2==1)odd++;
        }
        return odd>=0;
        
    }
};