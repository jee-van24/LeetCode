class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int res = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;

            while (true) {
                int maxfreq = 0;
                for (int i = 0; i < 26; i++)
                    maxfreq = max(maxfreq, freq[i]);

                if ((right - left + 1) - maxfreq <= k)
                    break;

                freq[s[left] - 'A']--;
                left++;
            }

            res = max(res, right - left + 1);
        }
        return res;
    }
};