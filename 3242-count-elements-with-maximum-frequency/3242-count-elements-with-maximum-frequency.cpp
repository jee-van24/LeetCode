class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>freq;
        int max_freq=0;
        for(int num:nums){
            freq[num]++;
            max_freq=max(max_freq,freq[num]);
        }
        int res=0;
        for(auto pair: freq){
            if(pair.second==max_freq){
                res+=pair.second;
            }
        }
        return res;
    }
};