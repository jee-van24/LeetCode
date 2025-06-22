class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int i : nums) {
            freq[i]++;
        }

        for (auto it : freq) {
            int f = it.second;
            if (f == 1) continue;

            bool isPrime = true;
            for (int j = 2; j < f; j++) {
                if (f % j == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime) return true;
        }

        return false;
    }
};
