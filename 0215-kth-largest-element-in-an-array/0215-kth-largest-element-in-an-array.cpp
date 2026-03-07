class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minheap;
        for(int i=0;i<nums.size();i++){
            //push the ele 
            minheap.push(nums[i]);
            while(minheap.size()>k){
                minheap.pop();
            }
        }
        return minheap.top();
    }
};