class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>res;
        long long num=0;
        for(int i=0;i<nums.size();i++){

            cout<<"before "<<num<<"     ";
            num=(num%5)*2+nums[i];
            cout<<num<<" ";
            if(num%5==0){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        return res;
    }
};