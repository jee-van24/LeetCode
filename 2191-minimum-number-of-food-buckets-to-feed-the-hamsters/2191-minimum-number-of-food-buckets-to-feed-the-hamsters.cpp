class Solution {
public:
    int minimumBuckets(string hamsters) {
        vector<int> arr;
        int hamsterCount = 0;
        int res = 0;

        // Convert string to numeric vector
        for (char c : hamsters) {
            if (c == 'H') {
                arr.push_back(1);
                hamsterCount++;
            } else {
                arr.push_back(0);
            }
        }

        int n = arr.size();

        // First pass: handle 'H.H' pattern
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] == 0 && arr[i - 1] == 1 && arr[i + 1] == 1) {
                arr[i - 1] = arr[i] = arr[i + 1] = -1;  // mark as processed
                res++;
                hamsterCount -= 2;
            }
        }

        // Second pass: handle remaining single Hs
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                if (i + 1 < n && arr[i + 1] == 0) {
                    arr[i + 1] = -1;
                    arr[i] = -1;
                    res++;
                    hamsterCount--;
                } else if (i - 1 >= 0 && arr[i - 1] == 0) {
                    arr[i - 1] = -1;
                    arr[i] = -1;
                    res++;
                    hamsterCount--;
                }
            }
        }

        if (hamsterCount > 0) {
            return -1;
        }

        return res;
    }
};
