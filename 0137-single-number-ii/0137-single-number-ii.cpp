class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int bitidx=0;bitidx<32;bitidx++){
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                if((nums[i]&(1<<bitidx))){
                    cnt++;
                }
            }
            if(cnt%3==1){
                res=res|(1<<bitidx);
            }
        }
        return res;
    }
};