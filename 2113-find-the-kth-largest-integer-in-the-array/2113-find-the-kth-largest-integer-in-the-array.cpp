class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto cmp=[](const string &a,const string &b){
            if(a.size()==b.size()){
                return a<b;
            }else{
                return a.size()<b.size();
            }
        };
        sort(nums.begin(),nums.end(),cmp);
        return nums[nums.size()-k];
    }
};