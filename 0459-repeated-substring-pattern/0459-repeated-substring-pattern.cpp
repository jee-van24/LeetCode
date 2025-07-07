class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string curr = "";
        for (int i = 0; i < s.size()/2; i++) {
            curr += s[i];
            string repeated = curr;

            while (repeated.size() < s.size()) {
                repeated += curr;
                if (repeated == s) {
                    return true;
                }
            }
        }
        return false;
    }
};
