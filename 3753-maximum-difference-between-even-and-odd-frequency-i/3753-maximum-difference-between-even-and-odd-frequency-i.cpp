class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>freq;
        //determine all the frequencies of each character 
        for(const char c : s){
            freq[c]++;
        }
        int max_odd=0,min_even=INT_MAX;
        for(auto pair: freq){
            if(pair.second%2==1){
                //youd want the odd freq to be as max as possibe
                max_odd=max(pair.second,max_odd);
            }else{
                //youd want even freq to be as min as possible 
                min_even=min(min_even,pair.second);
            }
        }
        if(min_even==INT_MAX)return max_odd;
        int res=max_odd-min_even;
        return res;
    }
};