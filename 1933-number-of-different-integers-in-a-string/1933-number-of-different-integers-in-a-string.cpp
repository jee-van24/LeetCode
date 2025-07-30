class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> seen;
        string temp = "";

        for (char ch : word) {
            if (isdigit(ch)) {
                temp += ch;
            } else {
                if (!temp.empty()) {
                    int i = 0;
                    while (i < temp.size() && temp[i] == '0') i++;
                    string num = temp.substr(i);
                    if (num == "") num = "0";
                    seen.insert(num);
                    temp.clear();
                }
            }
        }

        if (!temp.empty()) {
            int i = 0;
            while (i < temp.size() && temp[i] == '0') i++;
            string num = temp.substr(i);
            if (num == "") num = "0";
            seen.insert(num);
        }

        return seen.size();
    }
};
