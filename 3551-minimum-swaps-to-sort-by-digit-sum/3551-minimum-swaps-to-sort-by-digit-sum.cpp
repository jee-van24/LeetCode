class Solution {
public:
    int helper(int n){
        int s=0;
        while(n!=0){
            int rem=n%10;
            s+=rem;
            n/=10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        vector<int>sorted(nums);
        auto cmp=[this](int num1,int num2){
            int dsum1=helper(num1);
            int dsum2=helper(num2);
            if(dsum1!=dsum2){
                return dsum1<dsum2;
            }
            return num1<num2;
        };
        sort(sorted.begin(),sorted.end(),cmp);
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]=i;
        }
        int res=0;
        for(int i=0;i<nums.size();i++){
            int expectedval =sorted[i];
            int curr=nums[i];
            if(expectedval!=curr){
                int idx=map[sorted[i]];
                nums[i]=expectedval;
                nums[idx]=curr;
                map[expectedval]=i;
                map[curr]=idx;
                res++;
            }
        }
        return res;

    }
};