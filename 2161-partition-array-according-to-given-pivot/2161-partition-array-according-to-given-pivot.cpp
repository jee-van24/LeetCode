class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        unordered_set<int>s;
        int equal=0;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                res.push_back(nums[i]);
                s.insert(i);
            }else if(nums[i]==pivot){
                equal++;
            }
        }
        for(int i=0;i<equal;i++){
            res.push_back(pivot);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot){
                res.push_back(nums[i]);
            }
        }
        return res;

    }
};