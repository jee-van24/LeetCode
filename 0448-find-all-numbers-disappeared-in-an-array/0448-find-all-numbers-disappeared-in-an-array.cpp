class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n,0);
        vector<int>res;
        for(int i=0;i<n;i++){
            int idx=nums[i]-1;
            arr[idx]++;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                res.push_back(i+1);
            }
        }
        return res;

    }
};