class Solution {
public:
    int canBeTypedWords(string text, string brokenletters) {
        string curr = "";
        int res = 0;
        vector<char> check;
        unordered_map<char, int> map;
        for (auto ch : brokenletters) {
            check.push_back(ch);
        }

        for (auto ch : text) {
            if (ch == ' ') {
                bool flag = true;
                for (int i = 0; i < check.size(); i++) {
                    if (map.count(check[i])) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    res++;
                }
                map.clear();

            } else {
                map[ch]++;
            }
        }
       bool flag=true;
        // the last word 
        if (map.size()) {
            for (auto ch : check) {
                if (map.count(ch)) {
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            res++;
        }

        return res;
    }
};