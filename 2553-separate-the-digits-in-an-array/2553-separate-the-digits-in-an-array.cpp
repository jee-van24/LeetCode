class Solution {
public:
    void helper(int n,vector<int>&res){
        string s;
        while(n!=0){
            s+=(n%10)+'0';
            n/=10;
        }
        reverse(s.begin(),s.end());
        for(auto ch:s){
            res.push_back(ch-'0');
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>res;
        for(auto n:nums){
            helper(n,res);
        }
        return res;
    }
};