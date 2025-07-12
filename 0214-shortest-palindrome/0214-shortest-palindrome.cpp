class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        // Create a new string: s + '#' + reversed_s
        string temp = s + "#" + rev;

        // Build LPS array for temp
        int n = temp.size();
        vector<int> lps(n, 0);

        int len = 0;  // length of the previous longest prefix suffix
        int i = 1;

        while (i < n) {
            if (temp[i] == temp[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];  // fall back using LPS table
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // lps[n-1] gives the longest prefix of s which is also suffix of rev
        int palinPrefixLen = lps[n - 1];

        // Characters after the palindrome prefix in s need to be added in reverse
        string toAdd = s.substr(palinPrefixLen);
        reverse(toAdd.begin(), toAdd.end());

        return toAdd + s;
    }
};
