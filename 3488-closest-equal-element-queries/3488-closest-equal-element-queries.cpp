class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]].push_back(i);
        }
        int n=nums.size();
        vector<int>res(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            int idx=queries[i];
            int ele=nums[idx];
            auto &arr=map[ele];
            int sz=arr.size();
            if(arr.size()<=1){
                res[i]=-1;
                continue;
            }
            int low=0,high=arr.size()-1;
            int pos=-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(arr[mid]<=idx){
                    pos=mid;
                    low=mid+1;
                }else if(arr[mid]>=idx){
                    high=mid-1;
                }
            }
            int ridx=arr[(pos+1)%sz];
            int lidx=arr[(pos-1+sz)%sz];
            int d1=abs(lidx-idx);
            int cd1=abs(n-d1);
            int d2=abs(ridx-idx);
            int cd2=abs(n-d2);
            res[i]=min({d1,cd1,d2,cd2});
            
        }
        return res;
    }
};