class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(auto n:nums){
            cout<<n<<" ";
        }
        int res=0;
        int count=1;//assuming the first is same as the second
        for(int i=1;i<nums.size();i++){
            if(i==1&&nums[i]!=nums[i-1]){
                return -1;
            }
            if(nums[i]==nums[i-1]){
                count++;
                continue;
            }else{
                if(count==1){
                    return -1;
                }
                if(count%3==0){
                    res+=count/3;
                }else if(count%3==1){
                    res+=(count-4)/3+2;
                }else{
                    res+=(count-2)/3+1;
                }
                count=1;
            }
        }
        if (count == 1) return -1;
        if (count % 3 == 0) {
            res += count / 3;
        } else if (count % 3 == 1) {
            res += (count - 4) / 3 + 2;
        } else {
            res += (count - 2) / 3 + 1;
        }
        return res;
    }
};