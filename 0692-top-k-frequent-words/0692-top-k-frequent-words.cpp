class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(auto& word : words){
            freq[word]++;
        }

        vector<pair<int,string>> check;
        for(auto& pair : freq){
            check.push_back({pair.second, pair.first});
        }

        sort(check.begin(), check.end(), [](const pair<int,string>& a, const pair<int,string>& b){
            if(a.first == b.first)
                return a.second < b.second;  // lex order
            return a.first > b.first;        // freq desc
        });

        vector<string> res;
        for(int i = 0; i < k; ++i){
            res.push_back(check[i].second);
        }

        return res;
    }
};
