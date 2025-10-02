class Solution {
public:
    void dfs(int idx,vector<int>arr,vector<int>curr,int sum,int targ,int k,vector<vector<int>>&res){
        if(sum>targ||curr.size()>k)return ;
        if(curr.size()==k){
            if(sum==targ){
                res.push_back(curr);
                return;
            }
        }
        if(idx>=arr.size()){
            if(sum==targ&&curr.size()==k){
                res.push_back(curr);
            }
            return;
        }
        //i can include each idx at most once 
        //so i will consider 2 choices , including it and not including 
        curr.push_back(arr[idx]);
        dfs(idx+1,arr,curr,sum+arr[idx],targ,k,res);
        //now dont include the idx
        curr.pop_back();
        dfs(idx+1,arr,curr,sum,targ,k,res);
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        vector<int>curr={};
        vector<vector<int>>res;
        dfs(0,nums,curr,0,n,k,res);
        return res;
    }
};
