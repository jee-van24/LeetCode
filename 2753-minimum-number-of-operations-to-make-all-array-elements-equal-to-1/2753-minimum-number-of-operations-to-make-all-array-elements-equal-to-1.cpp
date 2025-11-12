class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int n:nums){
            map[n]++;
        }

        int ones=map[1];
        int len=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            for(int j=i+1;j<nums.size();j++){
                temp=gcd(temp,nums[j]);
                if(temp==1){
                    len=min(len,j-i+1);
                    break;
                }   
            }
        }
        if(len==INT_MAX)return -1;
        if(ones>0){
            return nums.size()-ones;
        }else{
            return (len-1)+(nums.size()-1);
        }

    }
};