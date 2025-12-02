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
    int minMirrorPairDistance(vector<int>& nums) {
        int res=INT_MAX;
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            if(map.count(nums[i])){
                res=min(res,i-map[nums[i]]);
            }
            map[rev(nums[i])]=i;
        }
        return res==INT_MAX?-1:res;
    }
};