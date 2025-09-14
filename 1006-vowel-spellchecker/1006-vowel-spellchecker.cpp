class Solution {
public:
    string tolower(string s) {

        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

    string replacevowels(string s) {
        for (char& c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                c = '*';
            }
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        vector<string> res;
        unordered_set<string> set;
        unordered_map<string, string> map1;
        unordered_map<string, string> map2;
        for (auto word : wordlist) {
            set.insert(word);
            auto lower = tolower(word);
            if (!map1.count(lower)) {
                map1[lower] = word;
            }
            auto vowstr=replacevowels(lower);
            if(!map2.count(vowstr)){
                map2[vowstr]=word;
            }
        }
        for(auto query:queries){
            if(set.count(query)){
                res.push_back(query);
                continue;
            }
            auto lowerq=tolower(query);
            if(map1.count(lowerq)){
                res.push_back(map1[lowerq]);//get the first word which you converted to lowercase to get the desired query
                continue;
            }
            auto replacevowelq=replacevowels(lowerq);
            if(map2.count(replacevowelq)){
                res.push_back(map2[replacevowelq]);//get the first word which you lowered case and replaced vowel to get the desired query
                continue;
            }
            res.push_back("");
        }

        return res;
    }
};