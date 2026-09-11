class Solution {
public:
    bool check(vector<int>&curr){
        if(curr[0]==0)return false;
        if(curr.back()%2!=0)return false;
        return true;
    }
    void backtrack(vector<int>&nums,vector<int>&curr,unordered_set<int>&res,vector<bool>&used){
        if(curr.size()==3){
            if(check(curr)){
                int num=0;
                num+=num*10+curr[0];
                num+=num*10+curr[1];
                num+=num*10+curr[2];
                res.insert(num);
            }
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            used[i]=true;
            curr.push_back(nums[i]);
            backtrack(nums,curr,res,used);
            used[i]=false;
            curr.pop_back();
        }
    }
    int totalNumbers(vector<int>& digits) {
        unordered_set<int>res;
        vector<bool>used(digits.size(),false);
        vector<int>curr;
        backtrack(digits,curr,res,used);
        return res.size();
    }
};