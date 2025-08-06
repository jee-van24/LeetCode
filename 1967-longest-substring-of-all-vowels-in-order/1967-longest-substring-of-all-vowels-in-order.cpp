class Solution {
public:
    int longestBeautifulSubstring(string word) {
        string vowel = "aeiou";
        int ptr = 0;
        int count = 0;
        bool atleast_one = false;
        int res = 0;

        for (char i : word) {
            if (i == vowel[ptr]) {
                atleast_one = true;
                count++;

                if (ptr == 4 && count > res) {
                    res = count;
                }

            } else if (ptr < 4 && i == vowel[ptr + 1] && atleast_one == true) {
                ptr++;
                atleast_one = true;
                count++;

                if (ptr == 4 && count > res) {
                    res = count;
                }

            } else {
                ptr = 0;
                count = 0;
                atleast_one = false;

                if (i == vowel[ptr]) {
                    atleast_one = true;
                    count++;
                }
            }
        }

        return res;
    }
};