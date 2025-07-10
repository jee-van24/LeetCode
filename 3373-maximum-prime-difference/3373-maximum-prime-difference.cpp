class Solution {
public:
    bool check(int&num){
        if(num==1)return false;
        if(num==2||num==3)return true;
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int res=0;
        int first=-1,second=-1;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            if(check(curr)==true){
                if(first==-1){
                    first=i;
                }else{
                    second=i;
                    res=max(res,second-first);
                }
            }
        }
        if(first==-1&&second==-1)return 0;
        if(first!=-1&&second==-1)return 0;
        return res;

    }
};