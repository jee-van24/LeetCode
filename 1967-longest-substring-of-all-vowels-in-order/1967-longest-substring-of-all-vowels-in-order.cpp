class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.length();
        int res = 0;
        int start = 0;

        while (start < n) {
            if (word[start] != 'a') {
                start++;
                continue;
            }

            int end = start;
            unordered_set<char> seen;
            seen.insert('a');

            while (end + 1 < n && word[end] <= word[end + 1]) {
                end++;
                seen.insert(word[end]);
            }

            if (seen.size() == 5) {
                res = max(res, end - start + 1);
            }

            start = end + 1;
        }

        return res;
    }
};
