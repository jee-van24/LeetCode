class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        vector<string> res;

        vector<int> startidx(26, -1);
        vector<int> endidx(26, -1);

        vector<bool> isvalid(26, true);

        for(int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';

            if(startidx[idx] == -1) {
                startidx[idx] = i;
            }

            endidx[idx] = i;
        }

        for(int c = 0; c < 26; c++) {

            if(startidx[c] == -1) {
                continue;
            }

            for(int i = startidx[c]; i <= endidx[c]; i++) {

                int idx = s[i] - 'a';

                if(startidx[idx] < startidx[c]) {
                    isvalid[c] = false;
                    break;
                }

                endidx[c] = max(endidx[c], endidx[idx]);
            }
        }

        int lastsubstringidx = INT_MAX;

        for(int i = s.size() - 1; i >= 0; i--) {

            int c = s[i] - 'a';

            if(!isvalid[c]) {
                continue;
            }

            if(startidx[c] == i && endidx[c] < lastsubstringidx) {

                res.push_back(s.substr(i, endidx[c] - i + 1));

                lastsubstringidx = i;
            }
        }

        return res;
    }
};