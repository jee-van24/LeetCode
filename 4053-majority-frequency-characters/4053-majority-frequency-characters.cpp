class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> freqMap;
        for(auto ch : s){
            freqMap[ch]++;
        }

        // build frequency table: freq -> count of chars with that freq
        unordered_map<int,int> freqTable;
        for(auto p : freqMap){
            freqTable[p.second]++;
        }

        int majorityFreq = 0;
        int majorityCnt = 0;
        for(auto p : freqTable){
            int k = p.first;
            int count = p.second; 
            if(count > majorityCnt || (count == majorityCnt && k > majorityFreq)){
                majorityFreq = k;
                majorityCnt = count;
            }
        }

        // collect all chars with majority frequency
        string res = "";
        for(auto p : freqMap){
            if(p.second == majorityFreq){
                res.push_back(p.first);
            }
        }

        return res; // order doesn’t matter
    }
};
