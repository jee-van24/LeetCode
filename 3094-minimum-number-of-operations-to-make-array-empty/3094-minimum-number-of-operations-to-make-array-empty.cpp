class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>map;
        int res=0;
        for(auto num:nums){
            map[num]++;
        }
        for(auto p:map){
            int freq=p.second;
            if(freq==1){
                return -1;
            }else if(freq%3==0){
                res+=freq/3;
            }else if(freq%3==1){
                res+=(freq-4)/3+2;
            }else{
                res+=(freq-2)/3+1;
            }
        }
        return res;
    }
};