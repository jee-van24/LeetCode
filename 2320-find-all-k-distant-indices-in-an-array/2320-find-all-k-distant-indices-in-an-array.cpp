class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        unordered_set<int>visited;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==key){
                for(int i=0;i<nums.size();i++){
                    if(abs(i-j)<=k){
                        if(visited.find(i)==visited.end()){
                            visited.insert(i);
                        }
                    }
                }
            }
        }
        vector<int> res(visited.begin(), visited.end());
        sort(res.begin(),res.end());
        return res;
    }
};