class Solution {
public:
    bool dfs(vector<int>&arr,int i){
        if(i<0||i>=arr.size()||arr[i]<0){
            return false;
        }
        if(arr[i]==0)return true;
        arr[i]*=-1;
        bool temp1=dfs(arr,i+(arr[i]*-1));
        bool temp2=dfs(arr,i-(arr[i]*-1));
        return temp1||temp2;
    }
    bool canReach(vector<int>& arr, int start) {
        bool res=dfs(arr,start);
        return res;
    }
};