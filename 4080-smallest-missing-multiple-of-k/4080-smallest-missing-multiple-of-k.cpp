class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int res=0;
        int check=k;
        unordered_map<int,int>map;
        for(auto n:nums){
            map[n]++;
        }
        while(true){
            if(map.count(check)){
                check+=k;
            }else{
                return check;
            }
        }
        return 0;
    
    }
};