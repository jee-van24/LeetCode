class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int res=0;
        vector<int>diff;
        for(int i=0;i<capacity.size();i++){
            diff.push_back(capacity[i]-rocks[i]);
        }
        sort(diff.begin(),diff.end());
        for(auto curr:diff){
            if(curr<=additionalRocks){
                res++;
                additionalRocks-=curr;
            }
        }
        return res;
    }
};