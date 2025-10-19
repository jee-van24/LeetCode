class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>seen;
            int odd=0,even=0;
            seen.insert(nums[i]);
            if(nums[i]%2==0){
                even++;
            }else{
                odd++;
            }
            for(int j=i+1;j<nums.size();j++){
                if(seen.find(nums[j])==seen.end()){
                    seen.insert(nums[j]);
                    if(nums[j]%2==0){
                        even++;
                    }else{
                        odd++;
                    }
                }
                if(even==odd){
                    res=max(res,j-i+1);
                }
            }
        }
        cout<<res;
        return res;
    }
};