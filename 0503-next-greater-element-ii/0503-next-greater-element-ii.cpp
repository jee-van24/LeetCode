class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>res(nums.size(),-1);
        stack<int>s;
        for(int i=2*nums.size()-1;i>=0;i--){
            int idx=i%nums.size();
            if(s.empty()){
                res[idx]=-1;
                s.push(nums[idx]);
            }else{
                while(!s.empty()&&s.top()<=nums[idx]){
                    s.pop();
                }
                if(!s.empty()){
                    res[idx]=s.top();
                }else{
                    res[idx]=-1;
                }
                s.push(nums[idx]);
            }
        }
        return res;
    }
};