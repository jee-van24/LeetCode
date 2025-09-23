class Solution {
public:
    int compareVersion(string version1, string version2) {
        int intp1 = 0, intp2 = 0;
        int i = 0;
        for (i = 0; i < version1.size(); i++) {
            if (version1[i] != '.') {
                int dig = version1[i] - '0';
                intp1 = intp1 * 10 + dig;
            } else {
                break;
            }
        }
        int j = 0;
        for (j = 0; j < version2.size(); j++) {
            if (version2[j] != '.') {
                int dig = version2[j] - '0';
                intp2 = intp2 * 10 + dig;
            } else {
                break;
            }
        }
        if (intp1 < intp2) return -1;
        else if (intp1 > intp2) return 1;
        else {
            vector<int> rev1, rev2;
            string temp = "";
            for (int k = i + 1; k < version1.size(); k++) {
                if (version1[k] != '.') temp += version1[k];
                else {
                    rev1.push_back(stoi(temp));
                    temp = "";
                }
            }
            if (!temp.empty()) {
                rev1.push_back(stoi(temp));
                temp = "";
            }

            for (int k = j + 1; k < version2.size(); k++) {
                if (version2[k] != '.') temp += version2[k];
                else {
                    rev2.push_back(stoi(temp));
                    temp = "";
                }
            }
            if (!temp.empty()) {
                rev2.push_back(stoi(temp));
                temp = "";
            }

            int n = max(rev1.size(), rev2.size());
            for (int idx = 0; idx < n; idx++) {
                int val1 = idx < rev1.size() ? rev1[idx] : 0;
                int val2 = idx < rev2.size() ? rev2[idx] : 0;
                if (val1 < val2) return -1;
                else if (val1 > val2) return 1;
            }
        }
        return 0;
    }
};
