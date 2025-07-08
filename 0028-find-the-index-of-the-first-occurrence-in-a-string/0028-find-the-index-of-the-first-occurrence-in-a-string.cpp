class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0,f=0;
        while (i < haystack.length()) {
            char check = needle[j];
            if (haystack[f] == check && j < needle.length()) {
                j++;
                f++;
            } else {
                j = 0;
                i++;
                f=i;
            }
            if (j == needle.length()) {
                return i;
            }
        }

        return -1;
    }
};