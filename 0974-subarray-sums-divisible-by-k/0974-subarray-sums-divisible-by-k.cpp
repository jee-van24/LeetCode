class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res=0;
        unordered_map<int,int>map;
        int currsum=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if(currsum%k==0){
                res++;
                res+=map[0];
                map[0]++;
                continue;
            }
            int rem=(((currsum)%k)+k)%k;
            if(map.find(rem)!=map.end()){
                res+=map[rem];
            }
            map[rem]++;
        }
        cout<<(-2%6);
        return res;
    }
};