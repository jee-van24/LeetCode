class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>res;
        for(int right=0;right<nums.size();right++){
            while(!dq.empty()&&nums[dq.back()]<=nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);
            if(dq.front()<=right-k){
                dq.pop_front();
            }
            if(right+1>=k){
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};