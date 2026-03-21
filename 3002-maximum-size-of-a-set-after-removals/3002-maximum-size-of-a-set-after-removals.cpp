class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1,s2,common;
        for(auto n:nums1)s1.insert(n);
        for(auto n:nums2)s2.insert(n);
        //try to see the how many ele they have in common
        for(auto n:s1){
            if(s2.count(n)){
                common.insert(n);
            }
        }
        //unique elements other than common ones between both
        int unique1=s1.size()-common.size();
        int unique2=s2.size()-common.size();
        int n=nums1.size();
        //but what if unique elements are more than half the size , so we have to restrict ourselvex to keeping only half the size
        unique1=min(unique1,n/2);
        unique2=min(unique2,n/2);
        int needed1=n/2-unique1;
        int needed2=n/2-unique2;
        int neededOverall=min((int)common.size(),needed1+needed2);
        return unique1+unique2+neededOverall;


    }
};