class Solution {
public:
    int rev(int n){
        int num=0;
        while(n!=0){
            int rem=n%10;
            num=num*10+rem;
            n/=10;
        }
        return num;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>map;
        long long res=0;
        vector<int>arr;
        for(auto n:nums){
            arr.push_back(n-rev(n));
        }
        for(int i=0;i<arr.size();i++){
            if(map.count(arr[i])){
                res+=map[arr[i]];
            }
            map[arr[i]]++;
        }
        int mod=1e9+7;
        return res%mod;
    }
};